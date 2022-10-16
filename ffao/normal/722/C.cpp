#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int p[110000];
int l[110000];
int r[110000];
int added[110000];

long long S[110000];

long long ans[110000];
int n;
int a[110000];
int perm[110000];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void link(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) return;
	p[y] = x;
	l[x] = min(l[x], l[y]);
	r[x] = max(r[x], r[y]);
}

void solve() {
	scanf("%d", &n);
	REP(i,n) p[i]=l[i]=r[i]=i;
	REP(i,n) scanf("%d", &a[i]);
	REP(i,n) scanf("%d", &perm[i]);
	REP(i,n) S[i+1] = S[i] + a[i];
	reverse(perm,perm+n);

	set< pair<long long,int> > inters;
	for (int i = 0; i < n-1; i++) {
		int to_add = perm[i]-1;

		if (to_add != 0 && added[to_add-1]) {
			int rep = find(to_add-1);
			inters.erase({S[r[rep]+1] - S[l[rep]], rep});
			link(to_add, rep);
		}
		if (to_add != n-1 && added[to_add+1]) {
			int rep = find(to_add+1);
			inters.erase({S[r[rep]+1] - S[l[rep]], rep});
			link(to_add, rep);
		}

		int rep = find(to_add);
		inters.insert({S[r[rep]+1] - S[l[rep]], rep});

		added[to_add]=1;
		ans[n-i-2] = inters.rbegin()->first;
	}
	ans[n-1] = 0;

	REP(i,n) printf("%lld\n", ans[i]);
}


int main() {
    solve();
}