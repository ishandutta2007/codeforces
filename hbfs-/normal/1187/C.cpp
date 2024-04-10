#include <bits/stdc++.h>
#define N 1050
using namespace std;

int fa[N], a[N], t[N], L[N], R[N], n, m;
inline int rd() {int r;scanf("%d",&r);return r;	}

int gf(int x) {return fa[x] == x ? x : fa[x] = gf(fa[x]);}

int main() {
	n = rd(), m = rd();
	for (int i=1;i<=m;i++)
		t[i] = (rd()^1), L[i] = rd(), R[i] = rd();
	
	for (int i=1;i<=n;i++) fa[i] = i;
	
	for (int i=1;i<=m;i++) {
		if (t[i] == 0) {
			for (int _=L[i];_<=R[i];_++) {
				if (gf( fa[_] ) != gf( fa[L[i]] )) {
					fa[ gf( fa[_] ) ] = gf(fa[ L[i] ]);
				}
			}
		}
	}
	
	for (int _=1;_<=n;_++) a[_] = n - gf( fa[_] ) + 1;
	
	int flag = 1;
	for (int i=1;i<=m;i++) if (t[i] == 1) {
		if (a[ R[i] ] >= a[ L[i] ])	flag = 0;
	}
	
	if (flag) {
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d%c", a[i], i==n?'\n':' ');	
	} else {
		puts("NO");	
	}
	return 0;	
}