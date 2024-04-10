#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

//int hidden[] = {1, 6, 4, 2, 3, 5, 4};

int askAnd(int i, int j) {
	cout << "and " << i + 1 << " " << j + 1 << endl;
	int x;
	cin >> x;
//	x = hidden[i] & hidden[j];
	return x;
}

int askOr(int i, int j) {
	cout << "or " << i + 1 << " " << j + 1 << endl;
	int x;
	cin >> x;
//	x = hidden[i] | hidden[j];
	return x;
}

void finish(int x) {
	cout << "finish" << " " << x << endl;
	exit(0);
}

const int N = 1e4 + 100;
const int LOG = 30;

int sure[3][LOG], val[N][LOG];

void solve3() {
	pii pos[3] = {mp(0, 1), mp(1, 2), mp(2, 0)};
	pii res[3];
	forn(t, 3) {
		int i1 = pos[t].fst;
		int i2 = pos[t].snd;
		int aa = askAnd(i1, i2);
		int bb = askOr(i1, i2);
		res[t] = mp(aa, bb);
		forn(j, LOG) {
			int a = (aa >> j) & 1;
			int b = (bb >> j) & 1;
			if (a == b) {
				val[i1][j] = a;
				val[i2][j] = a;
				sure[i1][j] = 1;
				sure[i2][j] = 1;
			}
		}
	}
	forn(t, 3) {
		int i1 = pos[t].fst;
		int i2 = pos[t].snd;
		int aa = res[t].fst;
		int bb = res[t].snd;
		forn(j, LOG) {
			int a = (aa >> j) & 1;
			int b = (bb >> j) & 1;
			if (a != b) {
				if (sure[i1][j]) val[i2][j] = 1 - val[i1][j];
				else if (sure[i2][j]) val[i1][j] = 1 - val[i2][j];
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
//	int n = 7, k = 7;
	int n, k;
	cin >> n >> k;
	forn(i, n) {
		forn(j, LOG) {
			val[i][j] = -1;
		}
	}
	solve3();
	forab(i, 2, n - 1) {
		int aa = askAnd(i, i + 1);
		int bb = askOr(i, i + 1);
		forn(j, LOG) {
			int a = (aa >> j) & 1;
			int b = (bb >> j) & 1;
			if (a == b) {
				val[i + 1][j] = val[i][j];
			} else {
				val[i + 1][j] = 1 - val[i][j];
			}
		}
	}
	vi vals(n, 0);
	forn(i, n) {
		forn(j, LOG) {
			if (val[i][j]) {
				vals[i] += (1 << j);
			}
		}
	}
	sort(all(vals));
	finish(vals[k - 1]);
	return 0;
}