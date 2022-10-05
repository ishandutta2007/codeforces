#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 500005
#define inf 0x3f3f3f3f
int n,L[maxn],R[maxn],idx;
vector<int>e[maxn];
void dfs(int u,int pa){
	for(auto v:e[u])if(v!=pa)dfs(v,u);
	L[u]=++idx;
	reverse(e[u].begin(),e[u].end());
	for(auto v:e[u])if(v!=pa)R[v]=++idx;
}
signed main()
{
	n=read();
	For(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0),R[1]=++idx;
	For(i,1,n)cout<<L[i]<<' '<<R[i]<<endl;
	return 0;
}