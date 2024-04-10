#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,num,lst[200002],ls[40000002],rs[40000002],pro[40000002],rt[100002],la,tot,inv[100002];
vector<int>D[200002];
inline void ins(re int &p,re int l,re int r,re int x,re int y){
	++tot,ls[tot]=ls[p],rs[tot]=rs[p],pro[tot]=1ll*pro[p]*y%M,p=tot;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x,y);
	else ins(rs[p],mid+1,r,x,y);
}
inline int ask(re int p,re int l,re int r,re int x){
	if(r<=x||!p)return pro[p];
	re int mid=l+r>>1,s=ask(ls[p],l,mid,x);
	if(x>mid)s=1ll*s*ask(rs[p],mid+1,r,x)%M;
	return s;
}
int main(){
	n=2e5,pro[0]=1; 
	for(re int i=2;i<=n;++i)
		if(!D[i].size())
			for(re int j=i;j<=n;j+=i)D[j].push_back(i);
	n=read(),inv[0]=1;
	for(re int i=1,w;i<=n;++i){
		rt[i]=rt[i-1],w=read(),inv[i]=1ll*inv[i-1]*ksm(w,M-2)%M;
		for(auto z:D[w]){
			re int x=w,s=1;
			while(x%z==0)s*=z,x/=z,ins(rt[i],0,n,lst[s],z),lst[s]=i;
		}
	}m=read();
	while(m--){
		re int l=(read()+la)%n+1,r=(read()+la)%n+1;if(l>r)swap(l,r);
		printf("%d\n",la=1ll*ask(rt[r],0,n,l-1)*inv[l-1]%M);
	}
}