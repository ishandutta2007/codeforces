#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef long long ll;
std::vector<int> e[N];int siz[N],c,n;
void dfs1(int x,int fa){
	siz[x]=1;if(fa)e[x].erase(std::find(e[x].begin(),e[x].end(),fa));
	for(auto v:e[x])if(v!=fa)dfs1(v,x),siz[x]+=siz[v],c+=siz[v]%2==1;
}
struct node{int mn;ll c0,c1;}f[N];ll ans;
inline node operator + (const node &a,const node &b){return a.mn==b.mn?(node){a.mn,a.c0+b.c0,a.c1+b.c1}:a.mn<b.mn?a:b;}
void dfs2(int x){
	f[x]={0,1,0};
	for(auto v:e[x]){
		if(siz[v]%2==0){if(c==n/2)ans+=1LL*siz[v]*(n-siz[v]);}
		dfs2(v);if(f[x].mn+f[v].mn+c+1==n/2)ans+=1LL*f[x].c1*f[v].c0+1LL*f[x].c0*f[v].c1;
		f[x]=f[x]+f[v];
	}
	if(siz[x]%2)f[x].c1+=f[x].c0;
	f[x].mn+=siz[x]%2?-1:1;
}
int main(){
	read(n);if(n%2)return puts("0"),0;
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0),dfs2(1);
	printf("%lld\n",ans);
	return 0;
}