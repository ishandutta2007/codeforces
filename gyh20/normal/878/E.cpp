#include<bits/stdc++.h>
#define re register
#define int __int128
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,a[100002],ans[100002],fa[100002],sum[100002],s1[100002],c[100002],inf=1e18,pw[100002],iv[100002],S[100002],siz[100002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Add(re int x,re int y){for(;x<=n;x+=x&(-x))add(c[x],y);}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))add(s,c[x]);return s;}
struct node{int l,id;};
vector<node>Q[100002];
inline int askk(re int l,re int r){
	return (S[r]-S[l-1]+M)*iv[l]%M;
}
signed main(){
	n=read(),m=read();
	for(re int i=pw[0]=iv[0]=1;i<=n;++i)pw[i]=Mod(pw[i-1]+pw[i-1]),iv[i]=1ll*(M+1>>1)*iv[i-1]%M;
	for(re int i=1;i<=n;++i)a[i]=read(),S[i]=((a[i]+M)*pw[i]+S[i-1])%M;
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),Q[y].push_back((node){x,i});
	for(re int i=1;i<=n;++i)fa[i]=i,sum[i]=a[i],s1[i]=(a[i]+M)%M,Add(i,s1[i]),siz[i]=1;
	for(re int i=1;i<=n;++i){
		re int x=i;
		while(x^1&&sum[x]>0){
			fa[x]=x-1,sum[root(x-1)]=min(sum[root(x-1)]+sum[x]*(1llu<<min(siz[root(x-1)],(__int128)63)),inf);
			add(s1[root(x-1)],1ll*s1[x]*pw[siz[root(x)]]%M),Add(x,M-s1[x]),Add(root(x-1),1ll*s1[x]*pw[siz[root(x)]]%M),siz[root(x-1)]+=siz[x];
			x=root(x);
		}
		for(auto z:Q[i]){
			re int s=Mod(ask(i)-ask(z.l)+M)*2%M,l=z.l+1,r=i,pos=z.l;
			while(l<=r){
				re int mid=l+r>>1;
				if(root(mid)==root(z.l))pos=mid,l=mid+1;
				else r=mid-1;
			}
			add(s,askk(z.l,pos));
			ans[z.id]=s;
		}
	}
	for(re int i=1;i<=m;++i)printf("%lld\n",(long long)ans[i]);
}