#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int>to[maxn];
int n,k,f[maxn];
inline int read() {
	int x=0;
	char ch=getchar();
	for(; ch<'0'||ch>'9'; ch=getchar());
	for(; ch>='0'&&ch<='9'; ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
void dfs(int x) {
	f[x]=1;
	for(unsigned i=0; i<to[x].size(); i++)
		if(!f[to[x][i]])
			dfs(to[x][i]);
}
int main() {
	n=read(),k=read();
	for(int i=1; i<=k; i++) {
		int a=read(),b=read();
		to[a].push_back(b),to[b].push_back(a);
	}
	int cnt=0;
	for(int i=1; i<=n; i++)
		!f[i]&&(dfs(i),cnt++);
	printf("%d\n",k-(n-cnt));
	return 0;
}