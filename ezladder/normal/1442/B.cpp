#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
int a[300007];
int b[300007];
const int mod = 998244353;

int nxt[300007];
int prv[300007];
int pos[300007];

int solve() {
	cin >> n >> k;
	set<int> can;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < k; ++i) cin >> b[i], can.insert(b[i]);

	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i;
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
	nxt[n - 1] = -1;

	int ans = 1;
	for (int i = 0; i < k; ++i) {
		can.erase(b[i]);
		int now = pos[b[i]];
		bool le = 0;
		bool ri = 0;
		if (prv[now] != -1) {
			if (can.find(a[prv[now]]) == can.end()) le = 1;
		}
		if (nxt[now] != -1) {
			if (can.find(a[nxt[now]]) == can.end()) ri = 1;
		}
		if (le == 0 && ri == 0) return 0;
		if (le && ri) {
			ans = ans * (ll)2 % mod;
			if (prv[prv[now]] != -1) {
				nxt[prv[prv[now]]] = now;
			}
			prv[now] = prv[prv[now]];
		} else if (le == 1) {
			if (prv[prv[now]] != -1) {
				nxt[prv[prv[now]]] = now;
			}
			prv[now] = prv[prv[now]];
		} else {
			if (nxt[nxt[now]] != -1) {
				prv[nxt[nxt[now]]] = now;
			}
			nxt[now] = nxt[nxt[now]];
		}
	}

	return ans;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cout << solve() << "\n";
	}

}