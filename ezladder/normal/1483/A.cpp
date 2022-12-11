#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;
vector<int> a[200007];

int ans[200007];
int sum[200007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i <= n; ++i) sum[i] = 0;
		for (int i = 0; i < m; ++i) {
			a[i].clear();
			int sz;
			cin >> sz;
			while (sz--) {
				int x; cin >> x;
				a[i].pb(x);
			}
			ans[i] = a[i][0];
			sum[a[i][0]]++;
		}

		int bad = (m + 1) / 2;

		int v = - 1;
		for (int i = 1; i <= n; ++i) if (sum[i] > bad) {
			v = i;
			break;
		}

		if (v != -1) {
			for (int i = 0; i < m; ++i) {
				if (!(sum[v] > bad)) break;
				if (a[i][0] == v) {
					if (a[i].size() > 1) {
						ans[i] = a[i][1];
						sum[v]--;
					}
				}
			}
			if (sum[v] > bad) {
				cout << "NO\n";
				continue;
			}
		}


		cout << "YES\n";
		for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
		cout << "\n";
	}

}