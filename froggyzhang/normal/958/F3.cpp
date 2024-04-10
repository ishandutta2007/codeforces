#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1009;
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
    Poly_fft(const vector<Complex> &_f):f(_f){}
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
    void Normal(){
    	for(auto &t:f){
			t.x=(ll)round(t.x)%mod;
			t.y=0;	
		}	
    }
};
template<int L>
typename Poly_fft<L>::initializer Poly_fft<L>::init;
template<int L>
vector<int> Poly_fft<L>::tr;
using poly=Poly_fft<20>;
int n,m,K,cnt[N];
poly Solve(int L,int R){
	if(L==R){
		poly tmp(vector<Complex>(cnt[L]+1,Complex(1.0,0)));
		return tmp;
	}
	int mid=(L+R)>>1;
	auto tmp=Mul(Solve(L,mid),Solve(mid+1,R));
	tmp.Normal();
	return tmp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	if(n<K){
		cout<<0<<'\n';
		return 0;	
	}
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++cnt[x];
	}
	poly A=Solve(1,m);
	cout<<(int)round(A[K].x)<<'\n';
	return 0;
}