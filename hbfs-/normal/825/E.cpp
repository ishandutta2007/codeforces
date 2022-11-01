#include <bits/stdc++.h>
#define N 1000500
using namespace std;

int n,m,h[N],cnt,tot,d[N],o[N];
priority_queue<int, vector<int>, less<int> >q;

inline int rd() {int r;scanf("%d",&r);return r;}
struct Edge{int b,n;}e[2*N];
void link(int a,int b) {e[++cnt] = (Edge){b,h[a]}, h[a] = cnt;}

int main() {
	n = rd(), m = rd();
	for (int i=1;i<=m;i++) {
		int a = rd(), b = rd();
		link(b, a);
		d[a]++;
	}
	for (int i=1;i<=n;i++) if (!d[i]) q.push(i);
	int tot = n;
	while (!q.empty()) {
		int u = q.top(); q.pop();
		o[u] = tot--;
		for (int i=h[u],v;v=e[i].b,i;i=e[i].n)
			if (--d[v] == 0) q.push(v);
	}
	for (int i=1;i<=n;i++) printf("%d%c",o[i],i==n?'\n':' ');
	return 0;
}