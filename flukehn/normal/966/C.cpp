#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ(x) ((int)(x).size())
void NO(){
	puts("No");
	exit(0);
}
const int N=1e5+11,M=63;
int n;
ll b[N];
ll p[N],tot=0;
vector<ll> g[M];
int r;
ll now;
void Dfs(int k){
	if(k<0)return;
	if(k==r){
		p[++tot]=g[r].back();
		now^=p[tot];
		g[r].pop_back();
		return;
	}
	int j;
	for(j=k-1;j>=0;--j)
		if(SZ(g[j]))break;
	if(~j && !(now>>j&1))Dfs(j);
	p[++tot]=g[k].back();
	now^=p[tot];
	g[k].pop_back();
	for(;j>=0;--j)if(SZ(g[j]) && !(now>>j&1))break;
	Dfs(j);
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	assert(cin>>n);
	for(int i=1;i<=n;++i){
		assert(cin>>b[i]);
		for(int k=M-1;k>=0;--k)
			if(b[i]>>k&1){
				g[k].push_back(b[i]);
				break;
			}
	}
	for(;!SZ(g[r]);)++r;
	int k;
	for(k=M-1;k>=0;--k){
		if(SZ(g[k]))break;
	}
	Dfs(k);
	if(tot!=n)NO();
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%I64d ",p[i]);
}