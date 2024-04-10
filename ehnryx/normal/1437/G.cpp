//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct AhoCorasick {
	enum {alpha = 26, first = 'a'};
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
  vector<multiset<int>> value;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
    for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = N.size(); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) {
    value.resize(pat.size());
		N.emplace_back(-1);
		for (int i=0; i<pat.size(); i++) insert(pat[i], i);
		N[0].back = N.size();
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			for (int i=0; i<alpha; i++) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vector<int> find(const string& word) {
		int n = 0;
		vector<int> res; // ll count = 0;
    for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
	int match(const string& word) {
		vector<int> r = find(word);
    int res = -1;
		for (int i=0; i<word.size(); i++) {
			int ind = r[i];
			while (ind != -1) {
        res = max(res, *value[ind].rbegin());
				ind = backp[ind];
			}
		}
		return res;
	}
};

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  unordered_map<string,int> idx;
  vector<int> remap(n), value(n);
  vector<string> names;
  for(int i=0, sid=0; i<n; i++) {
    string s;
    cin >> s;
    if(!idx.count(s)) {
      idx[s] = sid++;
      names.push_back(s);
    }
    remap[i] = idx[s];
  }

  AhoCorasick ac(names);

  for(int i=0; i<n; i++) {
    ac.value[remap[i]].insert(0);
  }

  for(int i=0; i<m; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int j, v;
      cin >> j >> v;
      int rj = remap[j-1];
      multiset<int>& all = ac.value[rj];
      all.erase(all.find(value[j-1]));
      all.insert(v);
      value[j-1] = v;
    } else {
      string s;
      cin >> s;
      cout << ac.match(s) << nl;
    }
  }

  return 0;
}