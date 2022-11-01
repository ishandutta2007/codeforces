#include <bits/stdc++.h>
#define N 100050
using namespace std;
int n,m;
int F[N];
vector<int> a[N];
inline int rd() { int r; scanf("%d",&r); return r; }
int main() {
	scanf("%d%d",&n,&m);
//	for (int i=0;i<=m;i++) a[0].push_back(0);
//	for (int i=1;i<=n;i++) a[i].resize(m+1);
	for (int i=1;i<=n;i++) a[i].push_back(0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			a[i].push_back(rd());
	for (int i=1;i<=n;i++) F[i] = i;
	for (int _=1;_<=m;_++) {
		int l = 1 , r = 1;
		while (r<n) {
			while (r+1<=n && a[r+1][_] >= a[r][_]) {
				int p1 = a[r+1][_];
				int p2 = a[r][_];
				r++;
			}
			F[l] = max(F[l],r);
			l = r+1; r = l;
		}
	}
	
	for (int i=1;i<=n;i++) F[i] = max(F[i],F[i-1]);
	int q=0; scanf("%d",&q);
	while (q--) {
		int l,r; scanf("%d%d",&l,&r);
		puts(F[l]>=r?"Yes":"No");
	}
	return 0;
}