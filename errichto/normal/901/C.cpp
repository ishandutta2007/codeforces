#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int inf = 1e9 + 5;
const int nax = 3e5 + 5;
vector<int> w[nax];
const int pot = 512 * 1024;
pair<int,int> tr[2*pot];
bool vis[nax];
int depth[nax];
typedef long long ll;
ll ordinary[nax];

void upd(int i) {
	tr[i] = make_pair(
		min(tr[2*i].first, tr[2*i+1].first),
		max(tr[2*i].second, tr[2*i+1].second)
	);
}

void mini(int & a, int b) {
	a = min(a, b);
}
void maxi(int & a, int b) {
	a = max(a, b);
}

vector<pair<int,int>> bad;

void dfs(int a, int par) {
	assert(!vis[a]);
	vis[a] = true;
	tr[pot+depth[a]] = {a, a};
	for(int x = (pot + depth[a]) / 2; x >= 1; x /= 2)
		upd(x);
	for(int b : w[a]) if(b != par) {
		if(!vis[b]) {
			debug() << imie(a) " -> " imie(b);
			depth[b] = depth[a] + 1;
			dfs(b, a);
		}
		else {
			int high = depth[a];
			int low = depth[b];
			debug() << imie(low) imie(high) imie(a) imie(b);
			if(low > high) continue;
			low += pot;
			high += pot;
			int small = min(tr[low].first, tr[high].first);
			int big = max(tr[low].second, tr[high].second);
			while(low < high - 1) {
				if(low % 2 == 0) {
					mini(small, tr[low+1].first);
					maxi(big, tr[low+1].second);
				}
				if(high % 2) {
					mini(small, tr[high-1].first);
					maxi(big, tr[high-1].second);
				}
				low /= 2;
				high /= 2;
			}
			bad.push_back({small, big});
			//~ printf("%d %d\n", small, big);
		}
	}
}

ll f1(int a, int b, int c) {
	//~ ll r = 0;
	//~ #warning faster!
	//~ for(int i = b; i < c; ++i) {
		//~ r += i - a;
	//~ }
	// (b - a) + (b + 1 - a) + ... + (c - 1 - a)
	return (ll) (b - a + c - 1 - a) * (c - b) / 2;
	//~ return r;
}

// the number of subintervals
ll cnt2(ll n) { return n * (n + 1) / 2; }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int a = 1; a <= n; ++a)
		if(!vis[a])
			dfs(a, -1);
	sort(bad.begin(), bad.end(), [&] (const pair<int,int> & a, const pair<int,int> & b) {
		return a.second < b.second;
	});
	vector<pair<int,int>> only;
	for(pair<int,int> & p : bad) {
		if(!only.empty() && only.back().second == p.second) {
			maxi(p.first, only.back().first);
			only.pop_back();
		}
		if(!only.empty() && only.back().first >= p.first) continue;
		only.push_back(p);
	}
	for(int i = 0; i < (int) only.size() - 1; ++i)
		assert(only[i].first < only[i+1].first);
	for(int i = 1; i < (int) only.size(); ++i) {
		ordinary[i] = f1(only[i-1].first, only[i-1].second, only[i].second);
		ordinary[i] += ordinary[i-1];
	}
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int A, B;
		scanf("%d%d", &A, &B);
		if(only.empty()) {
			printf("%lld\n", cnt2(B - A + 1));
			continue;
		}
		
		// find first that A <= only[i].first
		int low = 0, high = only.size();
		while(low < high) {
			int x = (low + high) / 2;
			if(A <= only[x].first) high = x;
			else low = x + 1;
		}
		int first_inside = low; // possibly == only.size()
		
		// find last that only[i].second <= B
		low = 0, high = only.size() - 1;
		while(low < high) {
			int x = (low + high + 1) / 2;
			if(only[x].second <= B) low = x;
			else high = x - 1;
		}
		int last_inside = low;
		if(only[last_inside].second > B) {
			--last_inside;
			assert(last_inside == -1);
		}
		
		if(last_inside < first_inside) {
			printf("%lld\n", cnt2(B - A + 1));
			continue;
		}
		
		ll ans = ordinary[last_inside] - ordinary[first_inside];
		ans += f1(only[last_inside].first, only[last_inside].second, B + 1);
		ans += cnt2(only[first_inside].second - A);
		printf("%lld\n", ans);
	}
}