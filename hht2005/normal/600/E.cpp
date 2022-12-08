#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
typedef pair<int,int> pii;
vector<int>to[maxn];
bool t[maxn][26];
int c[maxn],s[maxn],siz[maxn],fa[maxn],son[maxn],Max;
long long cnt,ans[maxn];
void pre(int x) {
	siz[x]=1;
	for(int y:to[x])
		if(y!=fa[x]) {
			fa[y]=x;
			pre(y);
			siz[x]+=siz[y];
			if(siz[son[x]]<siz[y])
				son[x]=y;
		}
}
void clear(int x) {
	s[c[x]]=0;
	for(int y:to[x])
		if(y!=fa[x])clear(y);
}
void calc(int x) {
	s[c[x]]++;
	if(s[c[x]]==Max)cnt+=c[x];
	else if(s[c[x]]>Max)Max=s[cnt=c[x]];
	for(int y:to[x])
		if(y!=fa[x])calc(y);
}
void dfs(int x) {
	for(int y:to[x])
		if(y!=fa[x]&&y!=son[x]) {
			dfs(y);
			clear(y);
			Max=cnt=0;
		}
	if(son[x])dfs(son[x]);
	for(int y:to[x])
		if(y!=fa[x]&&y!=son[x])
			calc(y);
	s[c[x]]++;
	if(s[c[x]]==Max)cnt+=c[x];
	else if(s[c[x]]>Max)Max=s[cnt=c[x]];
	ans[x]=cnt;
}
int main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		to[a].push_back(b);
		to[b].push_back(a);//awefsrgt
	}
	pre(1);
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	puts("");
	return 0;
}