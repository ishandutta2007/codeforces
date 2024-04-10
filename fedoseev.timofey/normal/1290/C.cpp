#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
  
using namespace std;

typedef long long ll;

// http://e-maxx.ru/algo/dsu

const int N = 3e5 + 7;

pair <int, int> parent[N];
int rank[N];
int sz[N];
int cnt[N];
int fxd[N];
int cl_need[N];

void make_set (int v) {
	parent[v] = make_pair (v, 0);
	sz[v] = 1;
  cnt[v] = 1;
  fxd[v] = -1;
  cl_need[v] = -1;
}

int ans = 0;

pair<int,int> find_set (int v) {
	if (v != parent[v].first) {
		int parity = parent[v].second;
		parent[v] = find_set (parent[v].first);
		parent[v].second ^= parity;
	}
	return parent[v];
}

int get(int v) {
  if (fxd[v] == -1) {
    return min(cnt[v], sz[v] - cnt[v]);
  } else {
    auto p = find_set(fxd[v]);
    if (p.second == cl_need[v]) return cnt[v];
    else return sz[v] - cnt[v];
  }
}

void del(int v) {
  ans -= get(v);
}

void add(int v) {
  ans += get(v);
}

void fix(int v, bool ch) {
  auto p = find_set(v);
  del(p.first);
  fxd[p.first] = v;
  cl_need[p.first] = !ch;
  add(p.first);
}
 
void add_edge (int a, int b, int w) {
	pair<int,int> pa = find_set (a);
	a = pa.first;
	int x = pa.second;
 
	pair<int,int> pb = find_set (b);
	b = pb.first;
	int y = pb.second;
  if (a == b) {
    return;
  }
  del(a);
  del(b);
	if (sz[a] < sz[b])
    swap(a, b);
	parent[b] = make_pair(a, x ^ y ^ w);
  sz[a] += sz[b];
  cnt[a] += (x ^ y ^ w ? sz[b] - cnt[b] : cnt[b]);
  if (fxd[b] != -1) {
    fxd[a] = fxd[b];
    cl_need[a] = cl_need[b];
  }
  add(a);
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <vector <int>> who(n);
  string s;
  cin >> s;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int x;
      cin >> x;
      --x;
      who[x].push_back(i);
    }
  }
  for (int i = 0; i < k; ++i) make_set(i);
  for (int i = 0; i < n; ++i) {
    assert(who[i].size() <= 2);
    if (who[i].size() == 1) {
      fix(who[i][0], s[i] != '1');
    } else if (who[i].size() == 2) {
      add_edge(who[i][0], who[i][1], s[i] != '1');
    }
    cout << ans << '\n';
  }
}