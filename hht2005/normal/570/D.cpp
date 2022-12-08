#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
typedef pair<int,int> pii;
vector<int>to[maxn];
vector<pii>qry[maxn];
bool t[maxn][26];
char c[maxn];
int s[maxn],ans[maxn],siz[maxn],dep[maxn],son[maxn];
void pre(int x) {
	siz[x]=1;
	for(int y:to[x]) {
		dep[y]=dep[x]+1;
		pre(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void clear(int x) {
	t[dep[x]][c[x]-97]=0;
	s[dep[x]]=0;
	for(int y:to[x])
		clear(y);
}
void calc(int x) {
	t[dep[x]][c[x]-97]^=1;
	if(t[dep[x]][c[x]-97])s[dep[x]]++;
	else s[dep[x]]--;
	for(int y:to[x])
		calc(y);
}
void dfs(int x) {
	for(int y:to[x])
		if(y!=son[x]) {
			dfs(y);
			clear(y);
		}
	if(son[x])dfs(son[x]);
	for(int y:to[x])
		if(y!=son[x])
			calc(y);
	t[dep[x]][c[x]-97]^=1;
	if(t[dep[x]][c[x]-97])s[dep[x]]++;
	else s[dep[x]]--;
	for(pii q:qry[x])
		ans[q.second]=s[q.first]<=1;
}
int main() {
	int n,m,p,k;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) {
		scanf("%d",&p);
		to[p].push_back(i);
	}
	scanf("%s",c+1);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&p,&k);
		qry[p].push_back(make_pair(k,i));
	}
	pre(dep[1]=1);
	dfs(1);
	for(int i=1;i<=m;i++)
		puts(ans[i]?"Yes":"No");
	return 0;
}