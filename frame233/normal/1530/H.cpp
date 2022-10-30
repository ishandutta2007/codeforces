#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=15005,inf=0x3f3f3f3f;
int a[N],f[N],g[N],F[N],G[N];
int c1[N],c2[N],n;
void add1(int x,int C){for(;x;x-=lowbit(x))chmin(c1[x],C);}
int ask1(int x){int ans=inf;for(;x<=n+1;x+=lowbit(x))chmin(ans,c1[x]);return ans;}
void add2(int x,int C){for(;x<=n+1;x+=lowbit(x))chmax(c2[x],C);}
int ask2(int x){int ans=0;for(;x;x-=lowbit(x))chmax(ans,c2[x]);return ans;}
void MAIN(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int ans=1;
	for(int t=0;t<2;++t){
		memset(F,63,(n+3)<<2),memset(G,0,(n+3)<<2);
		if(!t)F[n]=a[n],G[n]=a[n];
		else for(int i=n-1;i>=1;--i)F[i]=a[i],G[i]=a[i];
		for(int k=2+t;;++k){
			memset(f,63,(n+3)<<2),memset(g,0,(n+3)<<2),memset(c1,63,(n+3)<<2),memset(c2,0,(n+3)<<2);
			add1(a[n],F[n]),add2(a[n],G[n]);
			for(int i=n-1;i>=1;--i){
				if(i+k-1<=n){
					if(G[i+k-1])add1(G[i+k-1],a[i+k-1]);
					if(F[i+k-1]<inf)add2(F[i+k-1],a[i+k-1]);
				}
				f[i]=ask1(a[i]+1),g[i]=ask2(a[i]-1),add1(a[i],F[i]),add2(a[i],G[i]);
			}
			bool flag=false;for(int i=1;i<=n;++i)flag|=f[i]<inf||g[i]>0;
			if(!flag)break;
			chmax(ans,k-t),memcpy(F,f,(n+3)<<2),memcpy(G,g,(n+3)<<2);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}