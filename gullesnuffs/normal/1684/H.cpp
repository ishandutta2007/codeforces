#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Segment {
	ll l, r;
	ll lo, hi;

	Segment() {
		lo = 0;
		hi = 0;
	}
};

set<pair<int, int>> visited;
map<vector<bool>, pair<bool, vector<pair<int, int>>>> cache;

pair<bool, vector<pair<int, int>>> bruteforce(const vector<bool>& s, int ind, int sum) {
	if (ind == 0) {
		vector<bool> reduced_s;
		vector<int> zero_pos;
		rep(i,0,sz(s)) {
			if (s[i] || sz(reduced_s) < 2 || reduced_s.back() || reduced_s[sz(reduced_s)-2]) {
				reduced_s.push_back(s[i]);
			} else {
				zero_pos.push_back(i);
			}
		}
		if (sz(zero_pos)) {
			pair<bool, vector<pair<int, int>>> res;
			if (cache.count(reduced_s)) {
				res = cache[reduced_s];
			} else {
				res = bruteforce(reduced_s, ind, sum);
				sort(all(res.second));
				cache[reduced_s] = res;
			}
			if (!res.first)
				assert(false);
			vector<pair<int, int>> ret;
			int i = 0;
			for (auto it : res.second) {
				while (i < sz(zero_pos) && zero_pos[i] <= it.first+i) {
					ret.emplace_back(zero_pos[i], zero_pos[i]+1);
					++i;
				}
				ret.emplace_back(it.first+i, it.second+i);
			}
			return make_pair(true, ret);
		}
	}
	if (visited.count(make_pair(ind, sum)))
		return make_pair(false, vector<pair<int, int>>());
	if (ind == sz(s)) {
		if (__builtin_popcount(sum) == 1) {
			return make_pair(true, vector<pair<int, int>>());
		}
	}
	int x = 0;
	rep(i,ind,sz(s)) {
		x = 2*x + s[i];
		auto res = bruteforce(s, i+1, sum+x);
		if (res.first) {
			auto v = res.second;
			v.emplace_back(ind, i+1);
			return make_pair(true, v);
		}
		if (i && !s[i] && !s[i-1])
			break;
	}
	visited.insert(make_pair(ind, sum));
	return make_pair(false, vector<pair<int, int>>());
}

vector<pair<int, int>> solve(vector<bool> s) {
	vector<Segment> segs;
	ll max_write = 0;
	ll num_ones = 0;
	rep(i,0,sz(s)) {
		num_ones += s[i];
	}
	if (!num_ones)
		return vector<pair<int, int>>();
	Segment cur_seg;
	cur_seg.l = 0;
	rep(i,0,sz(s)) {
		ll new_lo = cur_seg.lo + s[i];
		ll new_hi = cur_seg.hi*2 + s[i];
		if (new_hi-new_lo > max_write+1 || max_write > num_ones+5) {
			cur_seg.r = i;
			max_write += cur_seg.hi - cur_seg.lo;
			segs.push_back(cur_seg);			
			cur_seg = Segment();
			cur_seg.l = i;
			new_lo = s[i];
			new_hi = s[i];
		}
		cur_seg.lo = new_lo;
		cur_seg.hi = new_hi;
	}
	cur_seg.r = sz(s);
	segs.push_back(cur_seg);			
	vector<pair<int, int>> ans;
	ll sum = num_ones;
	ll target = 1;
	while (target < sum) {
		target *= 2;
	}
	while (sz(segs) > 0) {
		auto seg = segs.back();
		segs.pop_back();
		if (seg.hi-seg.lo <= target-sum) {
			sum += seg.hi-seg.lo;
			ans.emplace_back(seg.l, seg.r);
		} else {
			rep(i,seg.l,seg.r) {
				ans.emplace_back(i, i+1);
			}
		}
	}
	if (sum != target) {
		visited.clear();
		/*cerr << "Trying bruteforce for ";
		rep(i,0,sz(s))
			cerr << s[i];
		cerr << "\n";*/
		auto res = bruteforce(s, 0, 0);
		if (res.first) {
			return res.second;
		}
		/*cerr << "Failed for ";
		rep(i,0,sz(s))
			cerr << s[i];
		cerr << "\n";*/
		return vector<pair<int, int>>();
	}
	return ans;
}

void solve() {
	string s;
	cin >> s;
	/*int len = (rand()%50)+1;
	rep(i,0,len)
		s.push_back('0'+(rand()%2));*/
	vector<bool> sb(sz(s));
	rep(i,0,sz(s))
		sb[i] = s[i] - '0';
	auto ans = solve(sb);
	sort(all(ans));
	if (sz(ans) == 0) {
		cout << "-1" << "\n" << "\n";
	} else {
		cout << sz(ans) << "\n";
		ll sum = 0;
		for (auto it : ans) {
			ll x = 0;
			rep(i,it.first,it.second) {
				x = 2*x + sb[i];
			}
			sum += x;
			cout << it.first+1 << " " << it.second << "\n";
		}
		assert(ans[0].first == 0);
		assert(ans.back().second == sz(s));
		rep(i,1,sz(ans)) {
			assert(ans[i-1].second == ans[i].first);
		}
		assert(__builtin_popcount(sum) == 1);
		cout << "\n";
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	/*const int MAX = 20;
	rep(i,0,1<<MAX) {
		vector<bool> s;
		rep(j,0,MAX) {
			if (i&(1<<j))
				s.push_back(1);
			else
				s.push_back(0);
		}
		solve(s);
	}
	return 0;*/
	int T;
	cin >> T;
	while (T--)
		solve();
}