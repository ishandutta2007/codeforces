#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;

struct P {
	ll x, y;
	P(ll x = 0, ll y = 0) : x(x), y(y) {}
	P operator + (const P & b) const { return P(x+b.x, y+b.y); }
	P operator - (const P & b) const { return P(x-b.x, y-b.y); }
	P & operator += (const P & b) { return *this = *this + b; }
	P & operator -= (const P & b) { return *this = *this - b; }
	ll operator * (const P & b) const { return x*b.y - y*b.x; }
	ll dotProduct(const P & b) const { return x*b.x + y*b.y; }
	void wypisz() { printf("(%lld, %lld), ", x, y); }
	void wczytaj() { scanf("%lld%lld", &x, &y); }
	bool prawy() const { return x > 0 || (!x && y > 0); }
	bool lewy() const { return x < 0 || (!x && y < 0); }
	bool operator < (const P & b) const { return *this * b < 0; }
	bool operator == (const P & b) const { return x == b.x && y == b.y; }
	ld norm() { return sqrt(x * x + y * y); }
};

bool cmp_lewoprawo(const P & a, const P & b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp_okrag(const P & a, const P & b) { return a.prawy() != b.prawy() ? a.prawy() : a * b < 0; }

vector<P> hull(vector<P> w) {
	// http://www.spoj.com/problems/GARDENHU/ - zwykle
	// http://codeforces.com/problemset/problem/166/B - razem z brzegami
	// http://www.spoj.com/problems/BSHEEP/ - wszystko
	sort(w.begin(), w.end(), cmp_lewoprawo);
	w.resize(unique(w.begin(), w.end()) - w.begin());
	vector<P> res;
	int L = 0;
	if(sz(res) == 1) return res;
	REP(_, 2) {
		for(auto & C : w) {
			while((int) res.size() >= L + 2) {
				P A = res[(int) res.size() - 2];
				P B = res.back();
				if((C-A) * (B-A) > 0) break;
				res.pop_back();
			}
			res.pb(C);
		}
		res.pop_back();
		reverse(w.begin(), w.end());
		L = (int) res.size();
	}
	return res;
}

const int N = 32, K = 205;
ld p[N][N][K];
int wzorek[2*N][N][N];

int pomik(int a) { return a * (a + 1) / 2; }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, times;
	scanf("%d%d", &n, &times);
	
	RI(i, n) FOR(j, i + 1, n) RI(low, i) FOR(high, j, n) wzorek[low+high][i][j]++;
	
	RI(t, times) {
		RI(i, n) FOR(j, i + 1, n) {
			p[i][j][t] += p[i][j][t-1] * (pomik(i - 1) + pomik(j - i - 1) + pomik(n - j));
		}
		RI(i, n) FOR(j, i + 1, n) RI(i2, j - 1) {
			if(i2 > i) p[i][j][t] += p[i2][j][t-1] * min(i, j - i2);
			else p[i][j][t] += p[i2][j][t-1] * min(i2, j - i);
		}
		RI(i, n) FOR(j, i + 1, n) FOR(j2, i + 1, n) {
			if(j2 > j) p[i][j][t] += p[i][j2][t-1] * min(j - i, n + 1 - j2);
			else p[i][j][t] += p[i][j2][t-1] * min(j2 - i, n + 1 - j);
		}
		RI(i, n) FOR(j, i + 1, n) RI(s, 2 * n) if(wzorek[s][i][j])
			p[i][j][t] += (1.L - p[s - i][s - j][t-1]) * wzorek[s][i][j];
		RI(i, n) FOR(j, i + 1, n) {
			p[i][j][t] *= 2.L / n / (n + 1);
			p[j][i][t] = p[i][j][t];
		}
	}
	
	int input[N];
	RI(i, n) scanf("%d", &input[i]);
	
	ld res = 0;
	RI(i, n) FOR(j, i + 1, n) res += input[i] < input[j] ? p[i][j][times] : 1.L - p[i][j][times];
	printf("%.9lf\n", (double) res);
	
	return 0;
}