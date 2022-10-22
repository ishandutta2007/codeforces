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

const int nax = 100 * 1000 + 10;
int n;
int A[nax], B[nax];
ll dp[nax];

struct Line {
	ll a, b;
	ll eval(int x) {
		return (ll)a * x + b;
	}
	long double intersect(Line &l) {
		return (long double)(l.b - b)/(a - l.a);
	}
};

deque<Line>hull;

int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> A[i];
	for(int i = 1; i <= n; ++i) cin >> B[i];
	dp[1] = 0;
	hull.PB({B[1], 0});
	for(int i = 2; i <= n; ++i) {
		while((int)hull.size() > 1 && hull.front().eval(A[i]) > hull[1].eval(A[i])) {
			hull.pop_front();
		}
		ll w = hull.front().eval(A[i]);
		dp[i] = w;
		Line to_add = {B[i], w};
		while((int)hull.size() > 1 && to_add.intersect(hull[(int)hull.size() - 2]) <= hull.back().intersect(hull[(int)hull.size() - 2])) {
			hull.pop_back();
		}
		hull.push_back(to_add);
	}
	cout << dp[n];
}