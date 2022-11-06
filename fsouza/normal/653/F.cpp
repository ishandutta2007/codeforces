#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

template <typename T, typename Cmp = less<T>>
struct RMQ {
  Cmp cmp;
  vector<vector<T>> range;
  RMQ(vector<T> &v) {
    int logn = 0; while (1<<logn+1 <= (int)v.size()) ++logn;
    range.resize(logn+1, vector<T>(v.size()));
    range[0] = v;
    for (int l = 1; l <= logn; ++l)
      for (int i = 0; i + (1<<l) <= (int)v.size(); ++i)
	range[l][i] = min(range[l-1][i], range[l-1][i + (1<<l-1)], cmp);
  }
  T query(int a, int b) {
    int size = b-a+1, l = __builtin_clz(1) - __builtin_clz(size);
    return min(range[l][a], range[l][b-(1<<l)+1], cmp);
  }
};

struct SuffixArray {
  vector<int> lcp;
  int n, h;
  vector<int> sa, invsa;
  bool cmp(int a, int b) { return invsa[a+h] < invsa[b+h]; }
  void ternary_sort(int a, int b) {
    if (a == b) return;
    int pivot = sa[a+rand()%(b-a)];
    int left = a, right = b;
    for (int i = a; i < b; ++i) if (cmp(sa[i], pivot)) swap(sa[i], sa[left++]);
    for (int i = b-1; i >= left; --i) if (cmp(pivot, sa[i])) swap(sa[i], sa[--right]);
    ternary_sort(a, left);
    for (int i = left; i < right; ++i) invsa[sa[i]] = right-1;
    if (right-left == 1) sa[left] = -1;
    ternary_sort(right, b);
  }
  SuffixArray() {}
  SuffixArray(vector<int> v): n(v.size()), sa(n) {
    v.push_back(INT_MIN);
    invsa = v;
    iota(sa.begin(), sa.end(), 0);
    h = 0; ternary_sort(0, n);
    for (h = 1; h <= n; h *= 2)
      for (int j = 0, i = j; i != n; i = j)
	if (sa[i] < 0) {
	  while (j < n && sa[j] < 0) j += -sa[j];
	  sa[i] = -(j-i);
	} else {
	  j = invsa[sa[i]]+1;
	  ternary_sort(i, j);
	}
    for (int i = 0; i < n; ++i) sa[invsa[i]] = i;
    lcp.resize(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (invsa[i] > 0) while (v[i+res] == v[sa[invsa[i]-1]+res]) ++res;
      lcp[invsa[i]] = res;
      res = max(res-1, 0);
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  string str(n, ' ');
  scanf("%s", &str[0]);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    values[i] = (str[i] == '(' ? +1 : -1);
  SuffixArray sa(values);

  vector<vector<int>> _withdelta(2*n+1);
  auto withdelta = [&_withdelta, n](int i) -> vector<int>& {
    return _withdelta[i + n];
  };
  
  vector<int> totdelta(n);
  for (int i = 0, delta = 0; i < n; ++i) {
    delta += values[i];
    totdelta[i] = delta;
    withdelta(delta).push_back(i);
  }
  RMQ<int> tdrmq(totdelta);

  lint result = 0;
  for (int si = 0; si < n; ++si) {
    int i = sa.sa[si];
    if (values[i] == +1) {
      int skip = sa.lcp[si];
      int from = i+skip;
      if (from < n) {
	int to;
	int totdeltabef = i > 0 ? totdelta[i-1] : 0;
	{
	  int l = i, r = n-1;
	  while (l < r) {
	    int m = (l+r+1)/2;
	    int totdeltamid = tdrmq.query(i, m) - totdeltabef;
	    if (totdeltamid >= 0) l = m;
	    else r = m-1;
	  }
	  to = l;
	}
	if (from <= to) {
	  vector<int> &cands = withdelta(totdeltabef);
	  int extra = (upper_bound(cands.begin(), cands.end(), to) -
		       lower_bound(cands.begin(), cands.end(), from));
	  result += extra;
	}
      }
    }
  }
  cout << result << endl;
  
  return 0;
}