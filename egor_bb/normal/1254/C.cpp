#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int askSign(int i, int j, int k) {
	cout << 2 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	int sign;
	cin >> sign;
	return sign;
}

ll askSquare(int i, int j, int k) {
	cout << 1 << " " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
	ll s;
	cin >> s;
	return s;
}

const int N = 1005;

ll square[N], sign[N];

bool cmp(int i, int j) {
	return square[i] > square[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int v = 0, u = 1;
	vector<int> l, r;
	forab(i, 2, n) {
		square[i] = askSquare(v, u, i);
		int s = askSign(v, u, i);
		if (s == -1) r.pb(i);
		else l.pb(i);
	}
	r.pb(v);
	l.pb(u);
	sort(all(l), &cmp);
	sort(all(r), &cmp);
	int v1 = l[0], v2 = r[0];
	forn(i, n) {
		if (i != v1 && i != v2) {
			sign[i] = askSign(v1, v2, i);
		}
	}
	cout << 0 << ' ';
	fornr(i, sz(r)) {
		int t = r[i];
		if (t != v2 && sign[t] == -1) cout << t + 1 << " ";
	}
	cout << v2 + 1 << " ";
	forn(i, sz(r)) {
		int t = r[i];
		if (t != v2 && sign[t] == 1) cout << t + 1 << " ";
	}
	fornr(i, sz(l)) {
		int t = l[i];
		if (t != v1 && sign[t] == 1) cout << t + 1 << " ";
	}
	cout << v1 + 1 << " ";
	forn(i, sz(l)) {
		int t = l[i];
		if (t != v1 && sign[t] == -1) cout << t + 1 << " ";
	}
	cout << endl;
    return 0;
}