#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[3010];
set <pii> s;

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a[i].fi, &a[i].se);
		s.insert(a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if ((a[i].fi + a[j].fi) & 1) continue;
			if ((a[i].se + a[j].se) & 1) continue;
			pii k = mp(a[j].fi + a[i].fi >> 1, a[j].se + a[i].se >> 1);
			if (s.find(k) != s.end()) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}