#include<bits/stdc++.h>
using namespace std;
const int MX=270000,P=998244353,g=3;
int Pow(int a,int b){int r=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)r=1LL*r*a%P;return r;}
namespace poly{
	void NTT(int N,int *a,int f=0){
		int i,j,l;
		for(i=j=0;i<N;++i){
			if(i>j)swap(a[i],a[j]);
			for(l=N>>1;(j^=l)<l;l>>=1);
		}
		for(l=1;l<N;l<<=1){
			int wn=Pow(g,(P-1)/l/2);
			//if(f)wn=Pow(wn,P-2);
			for(j=0;j<N;j+=l<<1){
				int x,y,w=1;
				for(i=0;i<l;++i,w=1LL*w*wn%P){
					x=a[i+j],y=1LL*a[i+j+l]*w%P;
					a[i+j]=(x+y)%P,a[i+j+l]=(x-y+P)%P;
				}
			}
		}
		if(f){
			reverse(a+1,a+N);
			l=Pow(N,P-2);
			for(i=0;i<N;++i)
				a[i]=1LL*a[i]*l%P;
		}
	}
	const int NX=MX<<1;
	void wk_inv(int N,int *a,int *b){
		static int c[NX];
		if(N==1){
			b[0]=Pow(a[0],P-2);
			return;
		}
		int M=N+1>>1;
		wk_inv(M,a,b);
		int i,L;
		for(L=1;L<N*2;L<<=1);
		for(i=0;i<N;++i)c[i]=a[i];
		for(i=N;i<L;++i)c[i]=0;
		NTT(L,c);
		NTT(L,b);
		for(i=0;i<L;++i)b[i]=(2-1LL*b[i]*c[i]%P+P)%P*b[i]%P;
		NTT(L,b,1);
		for(i=N;i<L;++i)b[i]=0;
	}

	int c[NX],d[NX],e[NX],f[NX],g[NX];
	void wk(int N,int *a,int *b){
		if(N==1){
			b[0]=1;
			return;
		}
		int M=N+1>>1,i;
		wk(M,a,b);
		for(i=0;i<N;++i)c[i]=b[i],d[i]=a[i];
		int L;
		for(L=1;L<N*3;L<<=1);
		for(i=N;i<L;++i)c[i]=d[i]=0;
		NTT(L,c),NTT(L,d);
		for(i=0;i<L;++i)e[i]=(1LL*c[i]*c[i]%P*d[i]%P-c[i]+P)%P;
		NTT(L,e,1);
		e[0]=e[0]+1;
		for(i=N;i<L;++i)e[i]=0;
		for(i=0;i<L;++i)f[i]=2LL*d[i]*c[i]%P;
		NTT(L,f,1);
		f[0]=(f[0]-1+P)%P;
		for(i=N;i<L;++i)f[i]=0;
		memset(g,0,sizeof g);
		wk_inv(N,f,g);
		NTT(L,e),NTT(L,g);
		for(i=0;i<L;++i)e[i]=1LL*e[i]*g[i]%P;
		NTT(L,e,1);
		for(i=0;i<N;++i)b[i]=(b[i]-e[i]+P)%P;
		for(i=N;i<L;++i)b[i]=0;
	}
}
int n,m;
int a[MX*2],b[MX*2];
int M;
int main(){
#ifdef flukehn
	freopen("a.txt","r",stdin);
#endif
	cin>>n>>m;
	int i,x;
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		a[x]=1;
	}
	x=max(n,m)+1;
	poly::wk(x,a,b);
	for(i=1;i<=m;++i)
	printf("%d\n",b[i]);
}