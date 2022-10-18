#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define pii pair<int,int>
#define vi vector < int >
#define sz(a) (int)a.size()
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
#define pb push_back
#define mp make_pair

const int INF = 1e9+5;
const int inf = 1e9;
const int N = 4e5;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int MOD = 1e9 + 7;
const int M = 3005;
int n;
int a[1005];
int id;
int cnt[1000005];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cur = 0;
	REP(i, n) {
		cin >> id;
		cnt[id]++;
		if (cnt[id] > cnt[cur]) {
			cur = id;
		}
	}
	cout << cur << endl;
	return 0;
}