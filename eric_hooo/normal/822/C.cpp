#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int l[200010], r[200010], x[200010]; 
pii idl[200010], idr[200010];
map <int, int> all;

bool cmpl(int x, int y){
	return l[x] < l[y];
}

bool cmpr(int x, int y){
	return r[x] < r[y];
}

int main(){
	int n, w; scanf("%d%d", &n, &w);
	for (int i = 0; i < n; i++){
		scanf("%d%d%d", &l[i], &r[i], &x[i]);
		idl[i] = mp(l[i], i);
		idr[i] = mp(r[i], i);
	}
	sort(idl, idl + n), sort(idr, idr + n);
	int now = n - 1;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = n - 1; i >= 0; i--){
		while (idr[now].fi >= idl[i].fi){
			int id = idr[now].se, need = w - (r[id] - l[id] + 1);
			if (all.count(need)) ans = min(ans, (long long)x[id] + all[need]);
			now--;
		}
		int id = idl[i].se;
		if (all.count(r[id] - l[id] + 1)) all[r[id] - l[id] + 1] = min(all[r[id] - l[id] + 1], x[id]);
		else all[r[id] - l[id] + 1] = x[id];
	}
	printf("%I64d\n", ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans);
	return 0;
}