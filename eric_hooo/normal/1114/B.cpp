#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[200010];
vector <pii> v;
vector <int> pos;

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		v.push_back(mp(a[i], i + 1));
	}
	sort(v.begin(), v.end()); reverse(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < m * k; i++){
		ans += v[i].fi;
		pos.push_back(v[i].se);
	}
	printf("%I64d\n", ans);
	sort(pos.begin(), pos.end());
	for (int i = 1; i < k; i++){
		printf("%d ", pos[i * m - 1]);
	}
	printf("\n");
	return 0;
}