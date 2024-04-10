#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

const int N=2e6+50;

const int Mod=998244353;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
ll inv(ll x) {
	return Fast(x,Mod-2);
}
namespace NTT {
	void DFT(ll *a,int n,int f) {
		static int rev[N],ww[N],iw[N],pn=0;
		if(pn!=n) {
			ll p=Fast(3,(Mod-1)/n);
			ww[0]=1;
			FOR(i,1,n-1) ww[i]=ww[i-1]*p%Mod;
			iw[n-1]=Fast(ww[n-1],Mod-2);
			DOR(i,n-1,1) iw[i-1]=iw[i]*p%Mod;
			FOR(i,0,n-1) rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
			pn=n;
		}
		int *w=(f>0)?ww:iw;
		FOR(i,0,n-1) if(rev[i]<i) swap(a[rev[i]],a[i]);
		for(int l=2; l<=n; l<<=1) {
			for(ll *p=a; p!=a+n; p+=l) {
				for(int i=0,m=l>>1; i<m; ++i) {
					ll t=p[i+m];
					p[i+m]=(p[i]+w[n/l*(i+m)]*t)%Mod;
					p[i]=(p[i]+w[n/l*i]*t)%Mod;
				}
			}
		}
		if(f<0) {
			ll t=Fast(n,Mod-2);
			FOR(i,0,n-1) a[i]=a[i]*t%Mod;
		}
	}
	void Poly_Mul(const ll *A,int LenA,const ll *B,int LenB,ll *C) {
		static ll a[N],b[N];
		int n=1;for(; n<LenA+LenB; n<<=1);
		FOR(i,0,n-1) a[i]=b[i]=0;
		FOR(i,0,LenA-1) a[i]=A[i];
		FOR(i,0,LenB-1) b[i]=B[i];
		DFT(a,n,1);DFT(b,n,1);
		FOR(i,0,n-1) C[i]=a[i]*b[i]%Mod;
		DFT(C,n,-1);
	}
	void Poly_Inv(const ll *A,int LenA,ll *B) {
		static ll a[N],b[N];
		B[0]=Fast(A[0],Mod-2);
		for(int l=2; (l>>1)<LenA; l<<=1) {
			int n=l<<1;
			FOR(i,0,n-1) a[i]=b[i]=0;
			FOR(i,l>>1,l-1) B[i]=0;
			FOR(i,0,(l>>1)-1) a[i]=B[i];
			FOR(i,0,l-1) b[i]=A[i];
			DFT(a,n,1);DFT(b,n,1);
			FOR(i,0,n-1) a[i]=a[i]*a[i]%Mod*b[i]%Mod;
			DFT(a,n,-1);
			FOR(i,0,l-1) B[i]=((B[i]<<1)-a[i])%Mod;
		}
	}
	void Poly_ln(const ll *A,int LenA,ll *C) { // A[0] = 1
		static ll a[N],b[N];
		Poly_Inv(A,LenA,b);
		FOR(i,0,LenA-2) a[i]=A[i+1]*(i+1)%Mod;
		Poly_Mul(a,LenA-1,b,LenA,C);
		DOR(i,LenA-1,0) C[i]=i?C[i-1]*Fast(i,Mod-2)%Mod:0;
	}
	void Poly_Exp(const ll *A,int LenA,ll *B) { // A[0] = 0
		static ll a[N],b[N];
		B[0]=1;
		for(int l=2; (l>>1)<LenA; l<<=1) {
			int n=l<<1;
			FOR(i,0,n-1) a[i]=b[i]=0;
			FOR(i,l>>1,l-1) B[i]=0;
			Poly_ln(B,l,b);
			FOR(i,0,(l>>1)-1) a[i]=B[i];
			FOR(i,0,l-1) b[i]=-b[i]+A[i];
			++b[0];
			DFT(a,n,1);DFT(b,n,1);
			FOR(i,0,n-1) a[i]=a[i]*b[i]%Mod;
			DFT(a,n,-1);
			FOR(i,0,l-1) B[i]=a[i];
		}
	}
}
ll a[N],f[N],g[N],h[N];
ll Fac[N],Inv[N];
int main() {
	int n;
	scanf("%d",&n);
	
	Fac[0]=1;
	FOR(i,1,n) Fac[i]=Fac[i-1]*i%Mod;
	Inv[n]=Fast(Fac[n],Mod-2);
	DOR(i,n,1) Inv[i-1]=Inv[i]*i%Mod;
	
	FOR(i,1,(n-1)/2) a[i]=inv(i);
	NTT :: Poly_Exp(a,n+1,f);
	
	FOR(i,n-(n-1)/2-1,n-1) h[i]=f[i]*(n-i-2<0?0:Fac[n-i-2])%Mod;
	
	FOR(i,0,n) f[i]=f[i]*Fac[i]%Mod;
	
	NTT :: Poly_Mul(h,n+1,Inv,n+1,g);
	
	FOR(i,1,n) {
		ll r=0;
		if(i==1) {
			r=f[n-1];
		} else if(i-1<=(n-1)/2) {
//			FOR(j,0,n-i) if(i-1+j<=(n-1)/2) {
//				r=(r+Inv[j]*h[n-i-j])%Mod;
//			}
//			r=Fac[n-i]*Inv[i-2]%Mod*r%Mod;
//			if(i==2) cerr << Fac[n-i]*Inv[i-2]%Mod << " " << g[n-i] << endl;
			r=Fac[n-i]*Inv[i-2]%Mod*g[n-i]%Mod;
			r=r*Fac[i-1]%Mod;
		}
		if(r<0) r+=Mod;
		printf("%lld%c",r," \n"[i==n]);
	}
	return 0;
}