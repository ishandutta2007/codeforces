#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n;
int A[nax];
ll S[nax], W[nax];

struct Line {
	ll a, b;
	ll eval(ll x) {
		return (ll)a * x + b;
	}
	long double intersect(Line &l) {
		return (long double)(l.b - b)/(a - l.a);
	}
};

vector<Line>hull;

int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	hull.PB({0, 0});
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		S[i] = S[i - 1] + A[i];
		W[i] = W[i - 1] + (ll)i * A[i];
		int l = 0, r = (int)hull.size() - 1, mid;
		while(l < r) {
			mid = (l + r) / 2;
			if(hull[mid + 1].eval(S[i]) > hull[mid].eval(S[i])) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		for(int j = max(0, l - 5); j <= min((int)hull.size() -1, l + 5); ++j) ans = max(ans, hull[j].eval(S[i]) + W[i]);
		Line to_add = {-i, (ll)i * S[i] - W[i]};
		while((int)hull.size() > 1 && to_add.intersect(hull[(int)hull.size() - 2]) >= hull.back().intersect(hull[(int)hull.size() - 2])) {
			hull.pop_back();
		}
		hull.PB(to_add);
	}
	cout << ans;
}