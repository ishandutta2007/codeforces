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

const int N = 1e4;

int a[N];
vector<int> ans;

void singleRot(int pref) {
	ans.pb(pref + 1);
	reverse(a, a + pref + 1);
}

void rot(int l, int r) {
	//cerr << "ROT " << l << " " << r << '\n';
	singleRot(r);
	singleRot(r - l);
	singleRot(r);
/*	forn(i, 3) {
		cerr << a[i] << " ";
	}
	cerr << '\n';*/
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		forn(i, n) {
			cin >> a[i];
			a[i]--;
		}
		ans.clear();
		int bad = 0;
		for(int i = n - 1; i > 1; i -= 2) {
			int posI, posJ;
			forn(j, i + 1) {
				if (a[j] == i) posI = j;
				if (a[j] == i - 1) posJ = j;
			}
			if (posI % 2 != 0) {
				bad = 1;
				break;
			}
			if (posJ % 2 != 1) {
				bad = 1;
				break;
			}
			if (posI > posJ) {
				rot(posJ + 1, posI);
				singleRot(posJ + 1);
				singleRot(i);
			} else {
				singleRot(posI);
				singleRot(posJ - 1);
				singleRot(posJ + 1);
				singleRot(2);
				singleRot(i);
			}
		}
		if (bad) {
			cout << -1 << '\n';
		} else {
			cout << sz(ans) << "\n";
			for(int x : ans) cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}