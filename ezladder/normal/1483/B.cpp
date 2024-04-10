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

int n;
int a[100007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<deque<int>> t;
		deque<int> now, num;
		vector<deque<int>> fr;
		now.pb(a[0]);
		num.pb(0);
		for (int i = 1; i < n; ++i) {
			if (__gcd(a[i], a[i - 1]) == 1) {
				t.pb(now);
				now.clear();
				fr.pb(num);
				num.clear();
			}
			now.pb(a[i]);
			num.pb(i);
		}

		t.pb(now);
		fr.pb(num);
		vector<int> ans;

//		for (auto& c : t) {
///			for (int x : c) cout << x << ' ';
	//		cout << endl;
	//	}



		while (1) {
			int emp = 0;
			int uk = 0;
			vector<int> pos;
			while (1) {
				while (uk < t.size() && t[uk].size() == 0) {
					emp++;
					uk++;
				}
				if (uk != t.size()) {
					pos.pb(uk);
					uk++;
				} else break;
			}


			int WAS = 0;
			for (int i = 0; i < pos.size(); ++i) {
				int j = i + 1;
				if (j == pos.size()) j = 0;
				int x = pos[i];
				int y = pos[j];

				if (t[x].size() == 0) continue;

				if (__gcd(t[x].back(), t[y][0]) == 1) {
					ans.pb(fr[y].front());
					fr[y].pop_front();
					t[y].pop_front();
					WAS++;
				} else {
					emp++;
				}
			}

		//	cout << uk << ' ' << emp << ' ' << WAS << endl;

			if (!WAS) break;
			if (emp * 2 > t.size() && t.size() > 30) {
				vector<deque<int>> nfr;
				vector<deque<int>> d;
				for (int i = 0; i < pos.size(); ++i) {


					int j = i + 1;
					int x = pos[i];

					if (i + 1 == pos.size()) {
						if (t[x].size() > 0) {
							d.emplace_back(t[x]);
							nfr.emplace_back(fr[x]);
						}
						continue;
					}

					int y = pos[j];
					if (t[x].size() > 0) {
						if (t[y].size() > 0 && __gcd(t[x].back(), t[y][0]) != 1) {
							for (int xx : t[y]) t[x].pb(xx);
							t[y].clear();
							for (int xx : fr[y]) fr[x].pb(xx);
							fr[y].clear();

							d.emplace_back(t[x]);
							nfr.emplace_back(fr[x]);
						} else {
							d.emplace_back(t[x]);
							nfr.emplace_back(fr[x]);
						}
					}
				}
				swap(fr, nfr);
				swap(d, t);
			}
		}

		cout << ans.size() << ' ';
		for (int x : ans) cout << x + 1 << ' ';
		cout << endl;
	}
}