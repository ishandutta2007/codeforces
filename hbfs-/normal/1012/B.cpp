#include <bits/stdc++.h>
#define N 400050
using namespace std;

int fa[N],n,m,q;
inline int rd() {int r;scanf("%d",&r);return r;}
int gf(int x) {	return fa[x] == x ? x : fa[x] = gf(fa[x]);}

int main() {
	n = rd(), m = rd(), q = rd();
	int tot = n+m-1;
	for (int i=1;i<=n+m-1;i++) fa[i] = i;
	for (int i=1;i<=q;i++) {
		int x = rd(), y = rd()+n;
		if (gf(x) != gf(y)) {
			fa[gf(x)] = gf(y);
			tot--;
		}
	}
	cout << tot << endl;
	return 0;
}