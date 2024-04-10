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
int t,n,m,a[1000002],ans,tot,f[1000002],lst[1000002];
map<int,int>V[100002];
inline int ask(re int x,re int y){
	if(x==0)return 0;
	re int Y=y;
	if(y==lst[x])return f[x];lst[x]=y;
	++tot;
	re int z,s=0;
	if(a[x]<=y)y=a[x];
	else z=(a[x]+y-1)/y,add(s,z-1),y=a[x]/z;
	s=1ll*x*s%M,add(s,ask(x-1,y));
	return f[x]=s;
}
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),V[i].clear(),lst[i]=-1;
		for(re int i=1;i<=n;++i)add(ans,ask(i,1e9));
		printf("%d\n",ans);
	} 
}