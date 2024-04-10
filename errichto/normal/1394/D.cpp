#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int nax = 2e5 + 5;
int tired[nax], height[nax];
vector<int> edges[nax];

typedef long long ll;
// using ll = long long;

ll INF = 1e18L + 5;
ll answer = INF;

// up, down
pair<ll, ll> dfs(int a, int par) {
	int deg = edges[a].size();
	ll sum = 0;
	vector<ll> diff;
	int cnt_up = 0, cnt_down = 0;
	for(int b : edges[a]) {
		if(b != par) {
			pair<ll,ll> his = dfs(b, a);
			ll up = his.first;
			ll down = his.second;
			if(height[b] > height[a]) {
				sum += up;
				cnt_up++;
			}
			else if(height[a] > height[b]) {
				sum += down;
				cnt_down++;
			}
			else {
				sum += up;
				diff.push_back(down - up);
				cnt_up++;
			}
		}
	}
	ll my_up = INF, my_down = INF;
	auto times = [&](int x, int y) {
		// debug() << imie(a) imie(deg) imie(y) imie(x);
		int bad = abs(x - y);
		assert((deg - bad) % 2 == 0);
		return bad + (deg - bad) / 2;
		// assert((deg - x - y) % 2 == 0);
		// return abs(x - y) + (deg - x - y) / 2;
	};
	auto consider = [&]() {
		for(bool am_up : {false, true}) if(par != -1) {
			// int times = abs((cnt_up + !am_up) - (cnt_down + am_up));
			// times 
			ll maybe = (ll) times(cnt_up+!am_up, cnt_down+am_up) * tired[a] + sum;
			if(am_up) {
				my_up = min(my_up, maybe);
			}
			else {
				my_down = min(my_down, maybe);
			}
		}
		if(par == -1) {
			// int times = abs(cnt_up - cnt_down);
			answer = min(answer, (ll) times(cnt_up,cnt_down) * tired[a] + sum);
		}
	};
	
	sort(diff.begin(), diff.end());
	
	consider();
	for(ll d : diff) {
		cnt_up--;
		cnt_down++;
		sum += d;
		consider();
	}
	debug() << imie(a) imie(my_up) imie(my_down);
	return {my_up, my_down};
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &tired[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &height[i]);
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, -1);
	printf("%lld\n", answer);
}