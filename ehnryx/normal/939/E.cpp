#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(chrono::high_resolution_clock::now().time_since_epoch().count()); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

double query(const vector<ll>& a, int v) {
	int n = a.size();
	if (n == 1) {
		return 0;
	}

	double first, second;
	int left, right, mid;
	left = 0;
	right = n-1;
	while (right - left > 1) {
		mid = (left + right)/2;
		first = v - (double)(a[mid] + v) / (mid+2);
		second = v - (double)(a[mid+1] + v) / (mid+3);
		if (first > second) {
			right = mid;
		} else {
			left = mid+1;
		}
	}

	first = v - (double)(a[left] + v) / (left+2);
	second = v - (double)(a[right] + v) / (right+2);
	return max(first, second);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();
	cout << fixed << setprecision(10);

	int q;
	cin >> q;

	int v;
	vector<ll> pref;
	ll sum = 0;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> v;
			sum += v;
			pref.push_back(sum);
		}
		else {
			cout << query(pref, v) << nl;
		}
	}

	return 0;
}