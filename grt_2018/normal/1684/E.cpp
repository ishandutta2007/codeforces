//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t, n, k;
map<int,int>sc;

int R;
int T[(1 << 18)];
int cnt[(1 << 18)];
const int INF = 1e9;

void upd(int a, int x) {
	a += R;
	T[a] += x;
	if(x > 0) cnt[a]++;
	else cnt[a]--;
	while(a > 0) {
		a >>= 1;
		T[a] = T[a << 1] + T[a << 1 | 1];
		cnt[a] = cnt[a << 1] + cnt[a << 1 | 1];
	}
}

int go_down(int x) {
	int v = 1;
	int w = 0;
	while(v < R) {
		if(T[v << 1] <= x) {
			x -= T[v << 1];
			w += cnt[v << 1];
			v = v << 1 | 1;
		} else {
			v = v << 1;
		}
	}
	int ile = min(cnt[v], x / (v - R));
	w += ile;
	return w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> k;
		sc.clear();
		R = 1;
		while(R <= n) R <<= 1;
		for(int i = 1; i < 2 * R; ++i) T[i] = cnt[i] = 0;
		for(int x, i = 0; i < n; ++i) {
			cin >> x;
			sc[x]++;
		}
		int sil = 0;
		for(auto it : sc) {
			upd(it.ND, it.ND);
			sil++;
		}
		int gaps = 0;
		int ans = INF;
		for(int mex = 0; mex <= n; ++mex) {
			if(mex > 0 && !sc.count(mex - 1)) {
				gaps++;
			}
			else if(mex > 0 && sc.count(mex - 1)) {
				upd(sc[mex - 1], -sc[mex - 1]);
				sil--;
			}
			if(k < gaps) break;
			int w = go_down(k); // ile moge sie pozbyc
			
			int diff = mex + sil - w;
			//cerr << mex << " " << diff << " " << w << " " << sil << "\n";
			ans = min(ans, diff - mex);
			
		}
		cout << ans << "\n";
	}
		
}