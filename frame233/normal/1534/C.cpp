#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005;
int p[N],q[N],rev[N];
bool vis[N];
void MAIN(){
	int n;read(n);
	memset(vis,0,n+3);
	for(int i=1;i<=n;++i)read(p[i]),rev[p[i]]=i;
	for(int i=1;i<=n;++i)read(q[i]);
	int ans=1;
	for(int i=1;i<=n;++i)if(!vis[i]){
		for(int u=i;!vis[u];u=rev[q[u]])vis[u]=true;
		ans=2*ans%1000000007;
	}
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}