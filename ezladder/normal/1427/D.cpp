#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
int a[55];

int get(int v) {
	for (int i = 1; i <= n; ++i) if (a[i] == v) return i;
}

void rev(vector<int>& t) {
	vector<vector<int> > d;
	int v = 1;
	for (int x : t) {
		vector<int> now;
		for (int i = 0; i < x; ++i) {
			now.pb(a[v++]);
		}
		d.pb(now);
	}
	reverse(all(d));
	v = 1;
	for (auto& x : d) {
		for (int y : x) a[v++] = y;
	}
}

vector<vector<int> > ans;

void go(vector<int>& t) {
	vector<int> f;
	for (int x : t) if (x > 0) f.pb(x);

	if (f.size() >= 2) {
		ans.pb(f);
		rev(f);
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];


	int w1 = (n + 1) / 2;
	int w2 = 0;

	if (n % 2 == 1) swap(w1, w2);

	int k1 = 0, k2 = 0;

	for (int it = 0; it < n; ++it) {
		vector<int> now;
		if (it % 2 == 0) {
			int pos = get(w1 + 1);
			now.pb(k2);
			now.pb(pos - k2 - 1);
			now.pb(n - now[0] - now[1] - k1);
			now.pb(k1);
		//	for (int x : now) cout << x << ' ';
	//		cout << endl;
	//		exit(0);
			go(now);
			++k1;
			++w1;
		} else {
			int pos = get(w2 + 1);
			now.pb(k1);
			now.pb(pos - k1 - 1);
			now.pb(n - now[0] - now[1] - k2);
			now.pb(k2);
			go(now);
			++k2;
			++w2;
		}
	//	for (int i = 0; i < n; ++i) cout << a[i + 1] << ' ';
	//		cout << endl;
		//exit(0);
	}

	cout << ans.size() << endl;
	for (auto& f : ans) {
		cout << f.size() << ' ';
		for (int x : f) cout << x << ' ';
		cout << "\n";
	}
}