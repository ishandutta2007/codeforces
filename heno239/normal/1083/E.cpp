#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

template<typename T>
class ConvecHullTrick {
private:
	// ()
	vector<pair<T, T>> lines;
	// ()x
	bool isMonotonicX;
	// /
	function<bool(T l, T r)> comp;

public:
	//  ( flag = true )
	ConvecHullTrick(bool flagX = false, std::function<bool(T l, T r)> compFunc = [](T l, T r) {return l >= r; })
		:isMonotonicX(flagX), comp(compFunc) {
		lines.emplace_back(0, 0);
	};

	// l1, l2, l3l2
	bool check(pair<T, T> l1, pair<T, T> l2, pair<T, T> l3) {
		if (l1 < l3) swap(l1, l3);
		return (long double)(l3.second - l2.second) * (l2.first - l1.first) >= (long double)(l2.second - l1.second) * (l3.first - l2.first);
	}

	// y=ax+b
	void add(T a, T b) {
		pair<T, T> line(a, b);
		while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))
			lines.pop_back();
		lines.emplace_back(line);
	}

	// if_i(x)x
	T f(int i, T x) {
		return lines[i].first * x + lines[i].second;
	}

	// if_i(x)x
	T f(pair<T, T> line, T x) {
		return line.first * x + line.second;
	}

	// x()
	T get(T x) {
		// ()x
		if (isMonotonicX) {
			static int head = 0;
			while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x)))
				++head;
			return f(head, x);
		}
		else {
			int low = -1, high = lines.size() - 1;
			while (high - low > 1) {
				int mid = (high + low) / 2;
				(comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
			}
			return f(high, x);
		}
	}
};
struct rec {
	ll x, y, val;
	bool operator<(const rec &r)const {
		if (r.x != x)return r.x > x;
		if (r.y != y)return r.y > y;
		return r.val > val;
	}
};
vector<rec> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n) {
		ll x, y, z; cin >> x >> y >> z;
		v.push_back({ x,y,z });
	}
	sort(v.begin(), v.end());
	ConvecHullTrick<ll> cht(true);
	ll ret = 0, ans = 0;
	rep(i, n) {
		ret = -cht.get(v[i].y) + v[i].x*v[i].y - v[i].val;
		cht.add(v[i].x, -ret);
		ans = max(ans, ret);
	}
	cout << ans << endl;
	return 0;
}