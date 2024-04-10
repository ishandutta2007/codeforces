#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

struct step {
	ll x[2][2];

	step() {
		forn(i, 2) forn(j, 2) x[i][j] = 0;
	}
	step(ll arr[2][2]) {
		forn(i, 2) forn(j, 2) x[i][j] = arr[i][j];
	}
	step comb(step oth) {
		ll _x[2][2] = {{
			min(x[0][0] + oth.x[0][0], x[0][1] + oth.x[1][0]),
			min(x[0][0] + oth.x[0][1], x[0][1] + oth.x[1][1])},
			{
			min(x[1][0] + oth.x[0][0], x[1][1] + oth.x[1][0]),
			min(x[1][0] + oth.x[0][1], x[1][1] + oth.x[1][1])}};
		return step(_x);
	}
};

int ind(int x, int y) {
	int p = max(x, y);
	return y + (p - x);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<pii> d1(n), d2(n);
	forn(i, n-1) {
		cin >> d1[i].f >> d1[i].s >> d2[i].f >> d2[i].s;
		d1[i].f--; d1[i].s--;
		d2[i].f--; d2[i].s--;

		assert(d1[i].f == i);
		assert(d2[i].s == i);
	}

	vector<step> v(n);
	forn(i, n-1) {
		int a = ind(d1[i].f+1, d1[i].s), b = ind(d2[i].f, d2[i].s+1);
		int c = ind(d1[i+1].f, d1[i+1].s), d = ind(d2[i+1].f, d2[i+1].s);

		ll x[2][2] = {{abs(a-c), abs(a-d)}, {abs(b-c), abs(b-d)}};
		v[i] = step(x);
	}
	const int LG = 20;
	vector<vector<step>> jump(n, vector<step>(LG));

	forn(j, LG) {
		forn(i, n) {
			if(j == 0) {
				jump[i][j] = v[i];
			} else {
				if(i + (1 << j-1) < n) {
					jump[i][j] = jump[i][j-1].comb(jump[i + (1<<j-1)][j-1]);
				} else {
					jump[i][j] = jump[i][j-1];
				}
			}
		}
	}

	int m;
	cin >> m;
	forn(i, m) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1--; x2--; y1--; y2--;

		if(max(x1, y1) == max(x2, y2)) {
			cout << abs(ind(x1, y1) - ind(x2, y2)) << "\n";
			continue;
		}

		if(max(x1, y1) > max(x2, y2)) {
			swap(x1, x2);
			swap(y1, y2);
		}

		int a = max(x1, y1), b = max(x2, y2);
		step s = step(), t = step();
		s.x[0][0] = abs(ind(x1,y1) - ind(d1[a].f, d1[a].s));
		s.x[0][1] = abs(ind(x1,y1) - ind(d2[a].f, d2[a].s));
		t.x[0][0] = abs(ind(x2,y2) - ind(d1[b-1].f+1, d1[b-1].s));
		t.x[1][0] = abs(ind(x2,y2) - ind(d2[b-1].f, d2[b-1].s+1));

		ll bef = b-a;
		for(int j=LG-1; j>=0; j--) {
			if(a + (1<<j) < b) {
				s = s.comb(jump[a][j]);
				a += (1<<j);
			}
		}

		s = s.comb(t);
		cout << s.x[0][0] + bef << "\n";
	}

}