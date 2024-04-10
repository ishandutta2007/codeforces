#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int isz=4194304;
int W[isz],w[isz],rev[isz],iv[isz],N;
unsigned ll tmp[isz];
//vector 
int cs;
namespace Cipolla
{
	int _i,mod;
	struct com
	{
		int x,y;
		com operator*(const com&w)const{return {(int)((1ll*y*w.y%mod*_i+1ll*x*w.x)%mod),(int)((1ll*x*w.y+1ll*y*w.x)%mod)};}
	};
	com ksm(com a,int b)
	{
		com ans={1,0};
		while(b)
		{
			if(b&1)ans=ans*a;
			a=a*a,b>>=1;
		}
		return ans;
	}
	int ksm(int a,int b)
	{
		int ans=1;
		while(b)
		{
			if(b&1)ans=1ll*ans*a%mod;
			a=1ll*a*a%mod,b>>=1;
		}
		return ans;
	}
	bool check(int a){return ksm(a,(mod-1)/2)==1;}
	int solve(int A,int md)
	{
		if(!A)return A;
		mod=md;mt19937 G(218);
		if(!check(A))assert(0||(cout<<"There isn't 2cishengyu for A="<<A<<".\n",0));
		while(1)
		{
			int b=G()%mod;
			_i=(1ll*b*b-A+mod)%mod;
			if(b&&!check(_i))
			{
				int a1=ksm({b,1},(mod+1)/2).x,a2=mod-a1;
				return min(a1,a2);
			}
		}
	}
}
template<const int mod,const int GG>
struct poly
{
	vector<int>A;
	poly(){A.clear();}
	poly(const vector<int>&B):A(B){}
	int ksm(int a,int b)
	{
		int ans=1;
		while(b)
		{
			if(b&1)ans=1ll*ans*a%mod;
			a=1ll*a*a%mod,b>>=1;
		}
		return ans;
	}
	void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
	int red(int a){return (a>=mod)?a-=mod:a;}
	void re(int n){A.resize(n);}
	int size()const{return A.size();}
	int make(int n)
	{
		int I=ceil(log2(n));// 
		N=(1<<I);
		for(int i=0;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(I-1));
		W[0]=1,W[1]=ksm(GG,(mod-1)/N);
		for(int i=2;i<N;i++)W[i]=1ll*W[i-1]*W[1]%mod;
		return N;
	}
	int Make(int n)
	{
		int I=ceil(log2(n));// 
		N=(1<<I);
//		for(int i=0;i<N;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(I-1));
		W[0]=1,W[1]=ksm(GG,(mod-1)/N);
		for(int i=2;i<N;i++)W[i]=1ll*W[i-1]*W[1]%mod;
		return N;
	}
	void piv(int n)
	{
		iv[1]=1;
		for(int i=2;i<=n;i++)iv[i]=1ll*(mod-mod/i)*iv[mod%i]%mod;
	}
	void NTT(vector<int>&A,int n,int f)
	{
		for(int i=1;i<n;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
		for(int i=0;i<n;i++)tmp[i]=A[i];
		//mod17 
		for(int i=1,ct=0;i<n;i<<=1,++ct)
		{
			w[0]=1;
			for(int j=1;j<i;j++)w[j]=(f==1)?W[j*(N/(i<<1))]:W[N-j*(N/(i<<1))];//w_{2i}^i 
			for(int j=0;j<n;j+=(i<<1))
			{
				for(int k=j;k<j+i;k++)
				{
					++cs;
					int y=1ll*w[k-j]*tmp[k+i]%mod;
					tmp[k+i]=tmp[k]+mod-y,tmp[k]+=y;
				}
			}
			if(ct==17)for(int j=0;j<n;j++)tmp[j]%=mod;
		}
		int iv=ksm(n,mod-2);
		for(int i=0;i<n;i++)A[i]=tmp[i]*(f==-1?iv:1)%mod;
	}
	void NTT(int *A,int n,int f)
	{
		for(int i=1;i<n;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
		for(int i=0;i<n;i++)tmp[i]=A[i];
		//mod17 
		for(int i=1,ct=0;i<n;i<<=1,++ct)
		{
			w[0]=1;
			for(int j=1;j<i;j++)w[j]=(f==1)?W[j*(N/(i<<1))]:W[N-j*(N/(i<<1))];//w_{2i}^i 
			for(int j=0;j<n;j+=(i<<1))
			{
				for(int k=j;k<j+i;k++)
				{
					++cs;
					int y=1ll*w[k-j]*tmp[k+i]%mod;
					tmp[k+i]=tmp[k]+mod-y,tmp[k]+=y;
				}
			}
			if(ct==17)for(int j=0;j<n;j++)tmp[j]%=mod;
		}
		int iv=ksm(n,mod-2);
		for(int i=0;i<n;i++)A[i]=tmp[i]*(f==-1?iv:1)%mod;
	}
	void NTT(int f){/*cerr<<A.size()<<"$$\n",*/NTT(A,A.size(),f);}
	int& operator[](const int&w){return A[w];}
	poly& operator>>=(const int&w)
	{
		int sz=size()-w;
		for(int i=0;i<sz;i++)A[i]=A[i+w];
		re(sz);
		return *this;
	}
	poly operator>>(const int&w)const{poly B=*this;B>>=w;return B;}
	poly& operator<<=(const int&w)
	{
		int sz=size()+w;
		re(sz);
		for(int i=sz-1;i>=w;i--)A[i]=A[i-w];
		for(int i=0;i<w;i++)A[i]=0;
		return *this;
	}
	poly operator<<(const int&w)const{poly B=*this;B<<=w;return B;}
	poly& operator^=(const poly&w)//siz 
	{
		for(int i=0;i<(int)A.size();i++)A[i]=1ll*A[i]*w.A[i]%mod;
		return *this; 
	}
	poly operator^(const poly&w)const{poly C=*this;C^=w;return C;}
	void TTN(vector<int>&A,int n)
	{
		//mod17 
		for(int i=n>>1;i;i>>=1)
		{
			w[0]=1; 
			for(int j=1;j<i;++j)w[j]=W[j*(N/(i<<1))];
			for(int j=0;j<n;j+=i<<1)
				for(int k=j;k<j+i;++k)
				{
					int x=A[k],y=A[k+i],z=A[k];
					(z+=y)>=mod&&(z-=mod);
					y=(x-y+mod);
					y>=mod&&(y-=mod);
					A[k]=z,A[k+i]=1ll*y*w[k-j]%mod;
				}
		}
	}
	void INTT(vector<int>&A,int n)
	{
		for(int i=0;i<n;i++)tmp[i]=A[i];
		//mod17 
		for(int i=1,ct=0;i<n;i<<=1,++ct)
		{
			w[0]=1;
			for(int j=1;j<i;j++)w[j]=W[N-j*(N/(i<<1))];//w_{2i}^i 
			for(int j=0;j<n;j+=(i<<1))
			{
				for(int k=j;k<j+i;k++)
				{
					++cs;
					int y=1ll*w[k-j]*tmp[k+i]%mod;
					tmp[k+i]=tmp[k]+mod-y,tmp[k]+=y;
				}
			}
			if(ct==17)for(int j=0;j<n;j++)tmp[j]%=mod;
		}
		int iv=ksm(n,mod-2);
		for(int i=0;i<n;i++)A[i]=tmp[i]*iv%mod;
	}
	poly& operator*=(const poly&w)
	{
		if(!w.size())return A.clear(),*this; 
		poly B=w;
		int na=A.size(),nb=B.A.size();
		Make(na+nb-1),re(N),B.re(N);
		TTN(A,N),TTN(B.A,N);
		for(int i=0;i<N;i++)A[i]=1ll*A[i]*B.A[i]%mod;
		INTT(A,N);
		re(na+nb-1);
		return *this;
	}
	poly& operator*=(const int&w)
	{
		for(int i=0;i<(int)A.size();i++)A[i]=1ll*A[i]*w%mod;
		return *this;
	}
	poly& operator+=(const poly&w)
	{
		re(max(A.size(),w.A.size()));
		for(int i=0;i<(int)w.A.size();i++)ad(A[i],w.A[i]);
		return *this;
	}
	poly& operator-=(const poly&w)
	{
		re(max(A.size(),w.A.size()));
		for(int i=0;i<(int)w.A.size();i++)A[i]=red(A[i]-w.A[i]+mod);
		return *this;
	}
	poly operator*(const int&w)const{poly C=*this;C*=w;return C;}
	poly operator*(const poly&w)const{poly C=*this;C*=w;return C;}
	poly operator+(const poly&w)const{poly C=*this;C+=w;return C;}
	poly operator-(const poly&w)const{poly C=*this;C-=w;return C;}
	poly Der()
	{
		if(!A.size())return *this;
		poly B;B.re((int)A.size()-1);
		for(int i=0;i<(int)A.size()-1;i++)B.A[i]=1ll*A[i+1]*(i+1)%mod;
		return B;
	}
	poly Int()
	{
		poly B;B.re(A.size()+1),piv(B.A.size());
		for(int i=1;i<(int)B.A.size();i++)B.A[i]=1ll*A[i-1]*iv[i]%mod;
		return B;
	}
	poly Inv()
	{
		if(!A.size())return *this;
		assert(A[0]||(cout<<"Inv's A[0] shouldn't be 0\n",0));
		poly B,C;B.re(1),B.A[0]=ksm(A[0],mod-2);
		for(int len=1;len<(int)A.size();len<<=1)
		{
			poly lb=*this;lb.re(len<<1);
			make(len<<2),C=B,lb.re(N),C.re(N),lb.NTT(1),C.NTT(1);
			for(int i=0;i<N;i++)lb.A[i]=1ll*lb.A[i]*C.A[i]%mod*C.A[i]%mod;
			lb.NTT(-1),lb.re(len<<1);
			B*=2,B-=lb;
		}
		B.re(A.size());
		return B;
	}
	// 
	poly Sqrt()
	{
		if(!A.size())return *this;
		poly B,C;B.re(1),B.A[0]=Cipolla::solve(A[0],mod);
		for(int len=1;len<(int)A.size();len<<=1)
		{
			poly lb=*this;lb.re(len<<1);
			C=lb+B*B,B*=2,B.re(len<<1);// 
			B=C*B.Inv(),B.re(len<<1);
		}
		B.re(A.size());
		return B;
	}
	poly Ln()//1 
	{
		if(!A.size())return *this;
		assert(A[0]==1||(cerr<<"Ln's A[0] should be 1 \n",0));
		poly B=(Der()*Inv()).Int();
		B.re(A.size());
		return B;
	}
	poly Exp()//0 
	{
		if(!A.size())return *this;
		assert(A[0]==0||(cerr<<"Exp's should be 0 \n",0));
		poly B,C;B.re(1),B.A[0]=1;
		for(int len=1;len<(int)A.size();len<<=1)
		{
			B.re(len<<1);
			poly lb=(poly({1})-B.Ln()+*this);//2kLn 
			lb.re(len<<1),B.re(len),B*=lb,B.re(len<<1);
		}
		B.re(A.size());
		return B;
	}
	poly pw()
	{
		poly B=*this;
		int na=A.size();
		make(na+na-1),B.re(N);
		B.NTT(1),B^=B;
		B.NTT(-1);
		B.re(na+na-1);
		return B;
	}
	poly ksm(int m)
	{
		poly B=Ln();
		for(int i=0;i<(int)A.size();i++)B.A[i]=1ll*B.A[i]*m%mod;
		B=B.Exp();
		return B;
	}
	poly Ksm(int m)
	{
		if(m==0)
		{
			poly B;B.re(A.size()),B.A[0]=1;
			return B;
		}
		int mn=-1;
		for(int i=0;i<(int)A.size();i++)if(A[i]){mn=i;break;}
		if(mn==-1)
		{
			poly B;B.re(A.size());
			return B;
		}
		int nv=A[mn];
		for(int i=0;i<(int)A.size()-mn;i++)A[i]=A[i+mn];
		for(int i=(int)A.size()-mn;i<(int)A.size();i++)A[i]=0;
		poly B=(*this *ksm(nv,mod-2)).ksm(m);
		if(1ll*mn*m>(int)A.size())
		{
			poly B;B.re(A.size());
			return B;
		}
		if(mn)
		{
			for(int i=(int)A.size()-mn*m;i>=0;i--)B.A[i+mn*m]=B.A[i];
			for(int i=0;i<mn*m;i++)B.A[i]=0;
		}
		B*=ksm(nv,m);
		return B;
	}
	poly Rev()const
	{
		poly B=*this;
		reverse(B.A.begin(),B.A.end());
		return B;
	}
	poly operator/(const poly&w)const
	{
		if(A.size()<w.A.size())
		{
			poly B;
			B.re(1);
			return B;//0.
		}
		poly F=this->Rev(),G=w.Rev();
		int md=F.A.size()-G.A.size()+1;
		F.re(md),G.re(md);
		poly T=(F*G.Inv());
		T.re(md);
		return T.Rev();
	}
	poly operator%(const poly&w)const{poly B=*this-*this/w*w;B.re(min(A.size(),w.A.size()-1));return B;}//
	poly Sin(){int I=ksm(GG,(mod-1)/4);return ((*this*I).Exp()-(*this*(mod-I)).Exp())*(ksm(red(I+I),mod-2)%mod);}
	poly Cos(){int I=ksm(GG,(mod-1)/4);return ((*this*I).Exp()+(*this*(mod-I)).Exp())*(ksm(2,mod-2)%mod);}
	void print(const vector<int>&A)const
	{
		puts("Out the poly");
		for(int i=0;i<(int)A.size();i++)
//		out(A[i]);
		cout<<A[i]<<" ";
		puts("End out");
		puts("");
	}
	void print()const{print(A);}
	bool operator<(const poly&w)const{return size()>w.size();}
	//resize 
};
const int mod=998244353;
#define poly poly<mod,3>
int n;
ll m;
poly F,G;
const int xx=1e5+5;
int jiec[xx],ni[xx];
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=F.ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
}

signed main(){
	pre();
	n=read(),m=read();
	F.re(n+1),G.re(n+1);
	for(int i=0;i<=n;i++)F[i]=1ll*read()*jiec[i]%mod;
	for(int i=0;i<=n;i++)G[i]=ni[i];
	G=G.Rev();
	F*=G;
	for(int i=0;i<=n;i++)F[i]=F[i+n],F[i]=1ll*F[i]*ni[i]%mod;
	F.re(n+1);
	for(int i=0;i<=n;i++)
		F[i]=1ll*F[i]*F.ksm(F.ksm(i+1,mod-2),m%(mod-1))%mod;
	for(int i=0;i<=n;i++)F[i]=1ll*F[i]*(i&1?mod-1:1)%mod*jiec[i]%mod;
	for(int i=0;i<=n;i++)G[i]=ni[i];
	G=G.Rev();
	F*=G;
	for(int i=0;i<=n;i++)F[i]=F[i+n],F[i]=1ll*F[i]*ni[i]%mod*(i&1?mod-1:1)%mod;
	F.re(n+1);
	for(int i=0;i<=n;i++)cout<<F[i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}