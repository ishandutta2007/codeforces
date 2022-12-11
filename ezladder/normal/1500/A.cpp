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
int a[200007];
pair<int, int> was[5000007];
vector<int> cnt[5000007];


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]].pb(i);
	}

	vector<int> t;
	for (int i = 1; i < 5000007; ++i) if (cnt[i].size() > 1) {
		t.pb(i);
	}

	if (t.size() >= 2) {
		cout << "YES\n";
		cout << cnt[t[0]][0] + 1 << ' ' << cnt[t[1]][0] + 1 << ' ' << cnt[t[0]][1] + 1 << ' ' << cnt[t[1]][1] + 1;
		exit(0);
	}

	if (t.size() == 1) {

		if (cnt[t[0]].size() >= 4) {
			cout << "YES\n";
			for (int i = 0; i < 4; ++i) cout << cnt[t[0]][i] + 1 << ' ';
			exit(0);
		}


		was[t[0] * 2] = mp(cnt[t[0]][0], cnt[t[0]][1]);


		for (int i = 0; i < n; ++i) {
			if (a[i] != t[0]) {
				was[a[i] + t[0]] = mp(i, cnt[t[0]][0]);
			}
		}


	}

	if (t.size() == 0) t.pb(-1);

	for (int i = 0; i < n; ++i) {
		if (a[i] == t[0]) continue;
		for (int j = 0; j < i; ++j) {
			if (a[j] == t[0]) continue;
			
			int s = a[i] + a[j];
			

			if (was[s].x == 0 && was[s].y == 0) {
				was[s] = mp(i, j);
			} else {
				cout << "YES\n";
				cout << i + 1 << ' ' << j  + 1 << ' ' << was[s].x + 1 << ' ' << was[s].y + 1;
				exit(0);
			}
		}
	}


	cout << "NO";

}