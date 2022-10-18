#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define forn(i,n) REP(i,n)
#define rfor(i,a,b) RFOR(i,a,b)
#define x first
#define y second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define sz(f) (int)f.size()
#define vi vector < int > 
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
const int INF = 1e9;
const int inf = 1e9;
const double PI = acos(-1.0);
const int MOD = 500000003;
const int N = 2e5;
int n, k, q;
int f[N];
int a[N];
bool cmp(int i, int j) {
	return a[i] > a[j];
}
int main() {
//	freopen("input.txt","r",stdin);
	ios :: sync_with_stdio(false);
	int n;
	cin >> n >> k >> q;
	REP(i, n) {
		cin >> a[i];
	}
	int Q = 0;
	REP(i, q) {
		int t;
		cin >> t;
		if (t == 1) {
			int id;
			cin >> id; id--;
			f[Q++] = id;
			if (Q > k) {
				sort(f, f + Q, cmp);
				Q--;
			}
		} else {
			bool was = false;
			int id; cin >> id; --id;
			REP(j, Q) {
				if (f[j] == id) {
					was = true;
					break;
				}
			}
			if (was)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;	
}