#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int p[N],l[N],r[N];std::vector<int> e[N];
int lim[N],ans;
void dfs(int x){
	ll s=0;for(auto v:e[x])dfs(v),s+=lim[v];
	if(s<l[x])lim[x]=r[x],++ans;
	else lim[x]=std::min((ll)r[x],s);
}
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)e[i].clear();
	for(int i=2;i<=n;++i)read(p[i]),e[p[i]].pb(i);
	for(int i=1;i<=n;++i)read(l[i],r[i]);
	ans=0,dfs(1);printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}