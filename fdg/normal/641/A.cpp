#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y0 smthngy0
#define y1 smthngy1
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define str fuck2
#define ld long double
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 4e5 + 10;
const int INF = 1000000000; //1e9
const int inf = 2e9+1;
const double eps = 1e-9;
void finite() {
	cout << "FINITE" << endl;
	exit(0);
}
int n;
string s;
int len[N];
int main(){
	//FREIN("input.txt");
	ios :: sync_with_stdio(false);
	cin >> n;
	cin >> s;
	REP(i, n) cin >> len[i];
	int cur = 0;
	REP(i, 10000000) {
		if (s[cur] == '>') cur += len[cur];
			else cur -= len[cur];
		if (cur >= n || cur < 0) {
			finite();
		}
	}
	
	cout << "INFINITE" << endl;
	return 0;
}