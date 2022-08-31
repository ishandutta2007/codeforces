#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],b[200002],ans,A,B,lst[200002],nxt[200002],R[200002],L[200002],tg[200002],val[200002],val1[200002];
char s[1000002];
set<int>S[200002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=1e9;
		map<int,int>V,V1;
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=a[i];
		sort(b+1,b+n+1);
		for(re int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+n+1,a[i])-b,S[i].clear();
		for(re int i=1;i<=n;++i)S[a[i]].insert(i);
		for(re int i=1;i<=n;++i)L[i]=n+1,R[i]=tg[i]=val[i]=0;
		for(re int i=1;i<=n;++i){
			if(V.count(a[i]))lst[i]=V[a[i]];
			else lst[i]=0;
			V[a[i]]=i;
		}V.clear();
		for(re int i=n;i;--i){
			if(V.count(a[i]))nxt[i]=V[a[i]];
			else nxt[i]=n+1;
		}
		for(re int i=1;i<=m;++i){
			re int x=read(),y=read();
			L[y]=min(L[y],x),R[x]=max(R[x],y);
		}
		for(re int i=n-1;i;--i)L[i]=min(L[i],L[i+1]);
		for(re int i=2;i<=n;++i)R[i]=max(R[i],R[i-1]);
		for(re int i=1;i<=n;++i){
			val1[i]=0;
			if(L[i]<=i&&lst[i]>=L[i])tg[i]=1,val[i]=lst[i];
			if(L[i]<=i){
				re int pos=*S[a[i]].lower_bound(L[i]);
				if(pos^i)val1[i]=pos;
			}
		}
		re int mx=0,mn=1e9,fst=0;
		for(re int i=n;i;--i)if(tg[i])fst=i;
		if(!fst){
			puts("0");
			continue;
		}
		for(re int i=n;i;--i){
			if(mx>i)break;
			re int pos=min(fst,mn);
			pos=min(pos,i);
			ans=min(ans,i-pos+1);
			if(val1[i])mn=min(mn,val1[i]);
			mx=max(mx,val[i]);
		}
		printf("%d\n",ans);
	}
}