#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define re register
#define FOR(i,a,b) for(register int i=a;i<=b;i++)
#define ROF(i,a,b) for(register int i=a;i>=b;i--)
char _buf[100001],*_op(_buf),*_ed(_buf);
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(_ch<'0'||_ch>'9')(_ch=='-')?_f=-1:_f=1,_ch=gc;
	while(_ch>='0'&&_ch<='9')_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1<<19,mod=998244353,inv3=(mod+1)/3;
ll Pow(ll t,int x){
	ll s=1;
	while(x){
		if(x&1)s=s*t%mod;
		x>>=1,t=t*t%mod;
	}
	return s;
}
namespace poly{
	int r[N];
	V init(int n,int&lim){
		lim=1;int l=0;
		while(lim<=(n<<1))lim<<=1,++l;
		FOR(i,1,lim-1)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	}
	V NTT(int*a,int lim,int opt){
		FOR(i,1,lim-1)if(i<r[i])swap(a[i],a[r[i]]);
		for(re int i=1,w1;w1=Pow(opt>0?3:inv3,mod/(i<<1)),i<lim;i<<=1)
			for(re int j=0;j<lim;j+=i<<1)
				for(re int k=0,w=1,x,y;k<i;++k,w=1ll*w*w1%mod)
					x=a[j+k],y=1ll*w*a[i+j+k]%mod,a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
		if(opt<0&&(opt=Pow(lim,mod-2)))
			FOR(i,0,lim-1)a[i]=1ll*a[i]*opt%mod;
	}
	V deri(int*a,int*b,int n){FOR(i,0,n-2)b[i]=1ll*a[i+1]*(i+1)%mod;}
	V inte(int*a,int*b,int n){FOR(i,1,n-1)b[i]=1ll*a[i-1]*Pow(i,mod-2)%mod;}
	V get_inv(int*a,int n,int*b){
		if(n==1)return void(b[0]=Pow(a[0],mod-2));
		static int tmp[N],lim;
		get_inv(a,(n+1)>>1,b),init(n,lim);
		FOR(i,0,lim-1)tmp[i]=(i<n)*a[i];
		NTT(tmp,lim,1),NTT(b,lim,1);
		FOR(i,0,lim-1)b[i]=(2ll-1ll*tmp[i]*b[i]%mod+mod)%mod*b[i]%mod;
		NTT(b,lim,-1);FOR(i,n,lim-1)b[i]=0;
	}
	V Ln(int*a,int*b,int n){
		static int tmp[N],lim;
		deri(a,b,n),get_inv(a,n,tmp),init(n,lim);
		NTT(b,lim,1),NTT(tmp,lim,1);
		FOR(i,0,lim-1)tmp[i]=1ll*b[i]*tmp[i]%mod;
		NTT(tmp,lim,-1);FOR(i,0,lim-1)b[i]=0;
		inte(tmp,b,n);FOR(i,0,lim-1)tmp[i]=0;
	}
	V exp(int*a,int*b,int n){
		static int tmp[N],lim;
		if(n==1)return void(b[0]=1);
		exp(a,b,(n+1)>>1),Ln(b,tmp,n),init(n,lim);
		FOR(i,0,lim-1)tmp[i]=(i<n)*(a[i]-tmp[i]+mod)%mod;
		++tmp[0],NTT(tmp,lim,1),NTT(b,lim,1);
		FOR(i,0,lim-1)b[i]=1ll*tmp[i]*b[i]%mod;
		NTT(b,lim,-1);FOR(i,n,lim-1)b[i]=tmp[i]=0;
	}
	V Pow(int*a,int*b,int n,int k){
		static int tmp[N];
		Ln(a,tmp,n);FOR(i,0,n-1)tmp[i]=1ll*tmp[i]*k%mod;
		exp(tmp,b,n);FOR(i,0,n-1)tmp[i]=0;
	}
}
int A[N],B[N],C[N],n,m,k=100000;
int main(){
	n=getint(),m=getint();
	FOR(i,1,n)k=getint(),(k<=m)&&(C[k]++);C[0]++;
	FOR(i,1,m)C[i]=4ll*(mod-C[i])%mod;
	poly::Pow(C,B,m+1,mod+1>>1);
	B[0]++;
	poly::get_inv(B,m+1,A);
	FOR(i,0,m)A[i]=2ll*A[i]%mod;
	FOR(i,1,m)cout<<A[i]<<'\n';
	return 0;
}