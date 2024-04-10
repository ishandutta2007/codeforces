#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int INF = 0x3f3f3f3f;

template <class T, bool lin=true, bool rin=false>
struct IntervalSet {
  T inf; set<pair<T,T>> s;
  IntervalSet(T F): inf(F) {}
  bool cmp(const T& a, const T& b, bool l, bool r=false) {
    if (l||r) return a < b || a == b; else return a < b;
  }
  void insert(T a, T b) {
		auto it = s.upper_bound({a,inf});
		while (it != s.end() && cmp(it->first, b, lin, rin)) {
			b = max(b, it->second); it = s.erase(it);
		}
		if (it != s.begin() && cmp(a, (--it)->second, lin, rin)) {
			a = min(a, it->first); b = max(b, it->second); s.erase(it);
		}
		s.insert({a,b});
  }
  pair<T,T> find(T x) {
    if (s.empty()) { return {inf,inf}; }
    auto it = s.upper_bound({x,inf});
    if (it == s.begin()) return {inf,inf};
    if (cmp((--it)->second,x,!rin)) return {inf,inf};
    if (cmp(x,it->first,!lin)) return {inf,inf};
    return *it;
  }
};

const int N = 5e5 + 1;
int a[N], ans[N];
bool up[N], done[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	IntervalSet<int,true,true> is(INF);
	set<int> need;
	map<int,vector<int>> idx;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		idx[a[i]].push_back(i);
		is.insert(i, i);
		need.insert(i);
	}

	function<void(int,int,int)> answer = [&] (int l, int r, int v) {
		for(auto it = need.lower_bound(l); it!=need.end() && *it<=r; ) {
			ans[*it] = v;
			it = need.erase(it);
		}
	};

	int maxcnt = 0;
	for(auto it=idx.rbegin(); it!=idx.rend(); it++) {
		vector<int> fix;
		for(int i : it->second) {
			if(done[i]) continue;
			fix.push_back(i);
			pair<int,int> cur = is.find(i);
			if(cur.first < i && i < cur.second) {
				is.s.erase(cur);
				is.insert(cur.first, i-1);
				is.insert(i, i);
				is.insert(i+1, cur.second);
				if(!done[i-1]) fix.push_back(i-1);
				if(!done[i+1]) fix.push_back(i+1);
			} else if(cur.first < i) {
				is.s.erase(cur);
				is.insert(cur.first, i-1);
				is.insert(i, i);
				if(!done[i-1]) fix.push_back(i-1);
			} else if(i < cur.second) {
				is.s.erase(cur);
				is.insert(i, i);
				is.insert(i+1, cur.second);
				if(!done[i+1]) fix.push_back(i+1);
			}
			up[i] = true;
			if(i>1 && !up[i-1]) {
				is.insert(i-1, i);
			}
			if(i<n && !up[i+1]) {
				is.insert(i, i+1);
			}
		}

		for(int i : fix) {
			if(done[i]) continue;
			auto [l, r] = is.find(i);
			maxcnt = max(maxcnt, (r-l) / 2);
			int m = (l+r)/2;
			if(up[l] && up[r]) {
				answer(l, r, it->first);
				is.s.erase(make_pair(l, r));
				for(int j=l; j<=r; j++) {
					done[j] = true;
				}
			} else if(up[l]) {
				answer(l, m, it->first);
			} else if(up[r]) {
				answer(m+1, r, it->first);
			}
		}
	}

	cout << maxcnt << nl;
	for(int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}