#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

struct Prob {
	int id;
	int a, t;
	Prob (int a, int t, int i): a(a), t(t), id(i) {}
	bool operator < (const Prob& other) const {
		return t < other.t;
	}
};

int n, t;
vector<Prob> prob;

bool valid(int k) {
	if (k == 0) return true;
	int cnt = 0;
	int taken = 0;
	for (const Prob& pb : prob) {
		if (pb.a >= k) {
			taken += pb.t;
			cnt++;
			if (cnt == k) break;
		}
	}
	return cnt == k && taken <= t;
}

vector<int> getans(int k) {
	if (k == 0) return {};
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (prob[i].a >= k) {
			ans.push_back(prob[i].id);
			if (ans.size() == k) return ans;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> t;

	int ta, tt;
	for (int i = 0; i < n; i++) {
		cin >> ta >> tt;
		prob.push_back(Prob(ta, tt, i+1));
	}
	sort(prob.begin(), prob.end());

	int left, mid, right;
	left = 0;
	right = n;
	while (left <= right) {
		mid = (left + right) / 2;
		if (valid(mid))
			left = mid+1;
		else 
			right = mid-1;
	}

	if (!valid(mid)) {
		mid--;
	}

	cout << mid << nl;
	cout << mid << nl;
	cout << getans(mid) << nl;

	return 0;
}