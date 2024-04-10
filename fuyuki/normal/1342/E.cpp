#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define cint const int
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOF(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=1<<20|1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
I Pow(ll t,int x){
	ll s=1;
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
namespace poly{
	int lmt(1),r[N],w[N],inv[N];
	V cl(int*op,int*ed){memset(op,0,ed-op<<2);}
	I getLen(int n){return 1<<32-__builtin_clz(n);}
	V rev(int*a,int n){FOF(i,0,n)if(a[i])a[i]=mod-a[i];}
	V mul(cint*a,int n,int x,int*c){FOF(i,0,n)c[i]=1ll*a[i]*x%mod;}
	V add(cint*a,cint*b,int n,int*c){FOF(i,0,n)check(c[i]=a[i]+b[i]);}
	V del(cint*a,cint*b,int n,int*c){FOF(i,0,n)check(c[i]=a[i]+mod-b[i]);}
	V dot(cint*a,cint*b,int n,int*c){FOF(i,0,n)c[i]=1ll*a[i]*b[i]%mod;}
	V init(int n){
		int l=-1,wn;inv[0]=inv[1]=1;
		while(lmt<=n)lmt<<=1,l++;
		FOF(i,0,lmt)r[i]=(r[i>>1]>>1)|((i&1)<<l);
		FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		wn=Pow(3,mod>>++l),w[lmt>>1]=1;
		FOF(i,(lmt>>1)+1,lmt)w[i]=1ll*w[i-1]*wn%mod;
		ROF(i,(lmt>>1)-1,1)w[i]=w[i<<1];
		lmt=__builtin_ctz(lmt);
	}
	V DFT(int*a,int l){
		static unsigned long long tmp[N];
		int u=lmt-__builtin_ctz(l),t;
		FOF(i,0,l)tmp[i]=a[r[i]>>u];
		for(int i=1;i<l;i<<=1)for(int j=0,d=i<<1;j<l;j+=d)FOF(k,0,i)
			t=tmp[i|j|k]*w[i|k]%mod,tmp[i|j|k]=tmp[j|k]+mod-t,tmp[j|k]+=t;
		FOF(i,0,l)a[i]=tmp[i]%mod;
	}
	V IDFT(int*a,int l){reverse(a+1,a+l),DFT(a,l),mul(a,l,mod-mod/l,a);}
	V mul(cint*a,cint*b,int l,int*c){
		static int X[N],Y[N];
		copy(a,a+l,X),copy(b,b+l,Y);
		DFT(X,l),DFT(Y,l),dot(X,Y,l,c),IDFT(c,l);
	}
	V Inv(cint*a,int n,int*b){
		static int tmp[N],d,l;
		for(d=1,l=2,b[0]=Pow(a[0],mod-2);d<n;d<<=1,l<<=1){
			copy(a,a+l,tmp),mul(tmp,b,l,tmp),cl(tmp,tmp+d);
			mul(tmp,b,l,tmp),copy(tmp+d,tmp+l,b+d),rev(b+d,d);
		}
		cl(b+n,b+d),cl(tmp,tmp+d);
	}
	V inte(int*a,int n){ROF(i,n-1,1)a[i]=1ll*inv[i]*a[i-1]%mod;a[0]=0;}
	V deri(int*a,int n){FOR(i,0,n-2)a[i]=1ll*(i+1)*a[i+1]%mod;a[n-1]=0;}
	V Ln(cint*a,int n,int*b){
		static int tmp[N],l;
		copy(a,a+n,tmp),deri(tmp,n),Inv(a,n,b);
		l=getLen(n+n-1),mul(tmp,b,l,b),inte(b,n);
		cl(tmp,tmp+n),cl(b+n,b+l);
	}
	V Exp(cint*a,int n,int*b){
		static int tmp[N],d,l;
		for(d=2,l=4,b[0]=1;d<n<<1;d<<=1,l<<=1){
			Ln(b,d,tmp),tmp[0]--,del(a,tmp,d,tmp);
			mul(b,tmp,l,b),cl(b+d,b+l),cl(tmp,tmp+d);
		}
		cl(b+n,b+d);
	}
}
int A[N],C[N],n,m,k;
int fac[N],inv[N];
I calc(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	cin>>n>>k,poly::init(n+1<<1);
	inv[0]=inv[1]=1,fac[0]=1;
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod,inv[i]=1ll*inv[i-1]*inv[i]%mod;
	if(k==0)return cout<<fac[n],0;
	if(k>=n)return cout<<0,0;
	m=n-k;
	FOR(i,0,n-1)A[i]=inv[i+1];
	poly::Ln(A,n+1,C);
	FOR(i,0,n)C[i]=1ll*C[i]*m%mod;
	FOR(i,n+1,n*2+1)C[i]=0;
	memset(A,0,sizeof(A));
	poly::Exp(C,n+1,A);
	cout<<1ll*A[n-m]*fac[n]%mod*calc(n,m)%mod*2%mod;
	return 0;
}