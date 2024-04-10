#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
enum multiply_tag{
    brute_tag,fft_tag,mix_tag
};
struct Complex{
    double x,y;
    Complex(double _x=0,double _y=0){x=_x,y=_y;}
    friend Complex operator + (const Complex &a,const Complex &b){
        return Complex(a.x+b.x,a.y+b.y);
    }
    friend Complex operator - (const Complex &a,const Complex &b){
        return Complex(a.x-b.x,a.y-b.y);
    }
    friend Complex operator * (const Complex &a,const Complex &b){
        return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
    }
};
template<int L>
class Poly_fft{
    using poly=Poly_fft<L>;
    static constexpr double PI=acos(-1.0);
    vector<Complex> f;
    struct initializer{
        vector<Complex> GG[2][L+1];
        initializer(){
            for(int p=1;p<=L;++p){
                Complex buf1(cos(2*PI/(1<<p)),sin(2*PI/(1<<p)));
                Complex buf0(cos(2*PI/(1<<p)),-sin(2*PI/(1<<p)));
                GG[0][p].resize(1<<p);
                GG[1][p].resize(1<<p);
                GG[0][p][0]=GG[1][p][0]=Complex(1,0);
                for(int i=1;i<(1<<p);++i){
                    GG[0][p][i]=GG[0][p][i-1]*buf0;
                    GG[1][p][i]=GG[1][p][i-1]*buf1;
                }
            }
        }
    };
    static initializer init;
    static vector<int> tr;
    static int FFT_init(int n){
        int lim=1;
        while(lim<n)lim<<=1;
        tr.resize(lim);
        for(int i=0;i<lim;++i){
            tr[i]=((tr[i>>1]>>1)|(i&1?lim>>1:0));
        }
        return lim;
    }
    static void FFT(poly &A,int flag,int n){
        A.resize(n);
        for(int i=0;i<n;++i){
            if(i<tr[i])swap(A.f[i],A.f[tr[i]]);
        }
        for(int p=2,j=1;p<=n;p<<=1,++j){
            int len=p>>1;
            for(int k=0;k<n;k+=p){
                auto buf=init.GG[flag][j].begin();
                for(int i=k;i<k+len;++i,++buf){
                    Complex tmp=(*buf)*A.f[i+len];
                    A.f[i+len]=A.f[i]-tmp;
                    A.f[i]=A.f[i]+tmp;  
                }
            }   
        }
        if(!flag){
            for(int i=0;i<n;++i){
                A.f[i].x=A.f[i].x/n;
            }   
        }
    }
public:
    Poly_fft(const vector<int> &_f):f(_f){}
    Poly_fft(){}
    Poly_fft(int _n){f.resize(_n);}
    int size(){return f.size();}
    void resize(int _n){f.resize(_n);}
    vector<Complex>::reference operator [] (int x){
        return f[x];
    }
    friend poly Mul(poly A,poly B){
        int n=A.size()+B.size()-1;
        int lim=FFT_init(n);
        poly C(lim);
        FFT(A,1,lim),FFT(B,1,lim);
        for(int i=0;i<lim;++i){
            C[i]=A[i]*B[i];
        }
        FFT(C,0,lim);
        C.resize(n);
        return C;
    }
};
template<int L>
typename Poly_fft<L>::initializer Poly_fft<L>::init;
template<int L>
vector<int> Poly_fft<L>::tr;
using poly=Poly_fft<21>;
/*

*/
template<int H,int D,multiply_tag mtag>          
class unsigned_bigint{
    using bint=unsigned_bigint<H,D,mtag>;
    static constexpr int B=round(pow(H,D));
    vector<int> g;
public:
    unsigned_bigint(const vector<int> &_g):g(_g){}
    unsigned_bigint(int x=0){
        if(!x){g.resize(1);return;}
        while(x)g.push_back(x%B),x/=B;  
    }
    unsigned_bigint(string s){
        g.resize(((int)s.length()+D-1)/D);
        reverse(s.begin(),s.end());
        for(int i=0;i*D<(int)s.length();++i){
            for(int j=min(D,(int)s.length()-i*D)-1;j>=0;--j){
                g[i]=g[i]*H+s[i*D+j]-'0';
            }
        }   
    }
    int length(){
		int len=D*(g.size()-1);
		int x=g.back();
		while(x)x/=H,++len;
		return max(1,len);
	}
    bint &operator += (const bint &b){
        if(b.g.size()>g.size())g.resize(b.g.size());
        g.push_back(0);
        for(int i=0;i<(int)g.size();++i){
            if(i<(int)b.g.size())g[i]+=b.g[i];
            if(g[i]>=B)++g[i+1],g[i]-=B;    
        }
        while(g.size()>1&&!g.back())g.pop_back();
        return *this;
    }
    bint &operator -= (const bint &b){
        if(b.g.size()>g.size())g.resize(b.g.size());
        g.push_back(0);
        for(int i=0;i<(int)b.g.size();++i){
            if(i<(int)b.g.size())g[i]-=b.g[i];
            if(g[i]<0)--g[i+1],g[i]+=B; 
        }
        while(g.size()>1&&!g.back())g.pop_back();
        return *this;
    }
    bint &operator *= (const bint &b){
        vector<ll> tmp;
        if(mtag==brute_tag||(mtag==mix_tag&&1LL*g.size()*b.g.size()<=5e6)){
            tmp.resize(g.size()+b.g.size());
            for(int i=0;i<(int)g.size();++i){
                for(int j=0;j<(int)b.g.size();++j){
                    tmp[i+j]+=1LL*g[i]*b.g[j];  
                }
            }
            g.resize(g.size()+b.g.size());
        }
        else{
            poly F(g.size()),G(b.g.size());
            for(int i=0;i<(int)F.size();++i)F[i].x=g[i];
            for(int i=0;i<(int)G.size();++i)G[i].x=b.g[i];
            F=Mul(F,G);
            g.resize(F.size()+1);
            tmp.resize(F.size()+1);
            for(int i=0;i<(int)F.size();++i){
                tmp[i]=round(F[i].x);
            }
        }
        for(int i=0;i<(int)tmp.size();++i){
            g[i]=tmp[i]%B;
            if(tmp[i]>=B)tmp[i+1]+=tmp[i]/B;
        }
        while(g.size()>1&&!g.back())g.pop_back();
        return *this;
    }
    bint &operator /= (const bint &b){
		if(b.g.size()>g.size()){
			g=vector<int>(1);
		}
		else{
			bint a;
			a.g.resize(g.size()-b.g.size()+1);
			for(int i=g.size()-b.g.size();i>=0;--i){
				bint tmp(vector<int>(g.begin()+i,g.end()));
				g.erase(g.begin()+i,g.end());
				while(tmp>=b){
					tmp-=b,++a.g[i];
				}
				if(tmp>bint(0))g.insert(g.end(),tmp.g.begin(),tmp.g.end());
			}
			g=a.g;
			while(g.size()>1&&!g.back())g.pop_back();
		}
		return *this;
	}
    bint Pow(int b){
        bint ans(1);
        int k=0;
        while(b>=(1<<k))++k;
        for(int i=k-1;i>=0;--i){
        	ans=ans*ans;
        	if(b>>i&1)ans=ans*(*this);
        }
        return ans;
    }
    friend bint operator + (const bint &a,const bint &b){
        return bint(a)+=b;
    }
    friend bint operator - (const bint &a,const bint &b){
        return bint(a)-=b;
    }
    friend bint operator * (const bint &a,const bint &b){
        return bint(a)*=b;
    }
    friend bint operator / (const bint &a,const bint &b){
        return bint(a)/=b;
    }
    friend bool operator == (const bint &a,const bint &b){
        return a.g==b.g;
    }
    friend bool operator < (const bint &a,const bint &b){
        if(a.g.size()<b.g.size())return true;
        if(a.g.size()>b.g.size())return false;
        for(int i=a.g.size()-1;i>=0;--i){
            if(a.g[i]<b.g[i])return true;
            if(a.g[i]>b.g[i])return false;
        }
        return false;
    }
    friend bool operator > (const bint &a,const bint &b){
        return b<a;
    }
    friend bool operator <= (const bint &a,const bint &b){
        return !(a>b);
    }
    friend bool operator >= (const bint &a,const bint &b){
        return !(a<b);
    }
    friend ostream &operator << (ostream &out,const bint &a){
        string s="";
        if(!a.g.back())s="0";
        else{
            int x=a.g.back();
            while(x)s+=x%10+'0',x/=10;
            reverse(s.begin(),s.end());
        }
        out<<s;
        for(int i=(int)a.g.size()-2;i>=0;--i){
            s="";
            int x=a.g[i];
            for(int j=0;j<D;++j){
                s+=x%10+'0',x/=10;
            }
            reverse(s.begin(),s.end());
            out<<s; 
        }
        return out;
    }
};
using bint=unsigned_bigint<10,2,mix_tag>;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	bint A(s);
	if(A==1){cout<<1<<'\n';return 0;}
	bint A1=A,A2=(A+1)/2,A3=(A+3)/4;
	int len=log2(10)/log2(3)*((int)A3.length()-1);
	bint num(3);
	num=num.Pow(len);
	while(num<A3)num*=3,++len;
	int ans3=3*len+4;
	while(num<A2)num*=3,++len;
	int ans2=3*len+2;
	while(num<A1)num*=3,++len;
	int ans1=3*len;
	cout<<min(min(ans3,ans2),ans1)<<'\n';
	return 0;
}