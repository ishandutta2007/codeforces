#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10;
int t, n, m;
int p[nax];
pi cnt[nax];
bool done[nax];

bool check(int x) {
	for(int i = 1; i <= n; ++i) {
		p[i] = ((p[i] - x - 1 + n) % n) + 1;
		done[i] = false;
	}
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		if(!done[i]) {
			int u = i;
			while(!done[u]) {
				done[u] = true;
				u = p[u];
			}
			res++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		p[i] = ((p[i] + x - 1 + n) % n) + 1;
	}
	return n - res <= m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i <= n; ++i) {
			cnt[i] = {0, i};
		}
		for(int i = 1; i <= n; ++i) {
			cin >> p[i];
			if(p[i] >= i) {
				cnt[p[i] - i].ST--;
			} else {
				cnt[n - i + p[i]].ST--;
			}
		}
		sort(cnt, cnt + n);
		vi ans;
		for(int i = 0; i < min(n,5); ++i) {
			//cout << cnt[i].ST << " " << cnt[i].ND << "\n";
			if(check(cnt[i].ND)) {
				ans.PB((n - cnt[i].ND) % n);
			}
		}
		//cout << "-----\n";
		sort(ans.begin(), ans.end());
		cout << (int)ans.size() << " ";
		for(int x : ans) cout << x << " ";
		cout << "\n";
	}
}