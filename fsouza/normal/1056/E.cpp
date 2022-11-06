#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct suffix_array_t {
  vector<int> lcp; vector<vector<pair<int, int>>> rmq;
  int n, h; vector<int> sa, invsa;
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
  suffix_array_t() {}
  suffix_array_t(vector<int> v): n(v.size()), sa(n) {
    v.push_back(INT_MIN);
    invsa = v; iota(sa.begin(), sa.end(), 0);
    h = 0; ternary_sort(0, n);
    for (h = 1; h <= n; h *= 2)
      for (int j = 0, i = j; i != n; i = j)
	if (sa[i] < 0) {
	  while (j < n && sa[j] < 0) j += -sa[j];
          sa[i] = -(j-i);
	} else { j = invsa[sa[i]]+1; ternary_sort(i, j); }
    for (int i = 0; i < n; ++i) sa[invsa[i]] = i;
    lcp.resize(n); int res = 0;
    for (int i = 0; i < n; ++i) {
      if (invsa[i] > 0) while (v[i+res] == v[sa[invsa[i]-1]+res]) ++res;
      lcp[invsa[i]] = res; res = max(res-1, 0);
    }
    int logn = 0; while ((1<<(logn+1)) <= n) ++logn;
    rmq.resize(logn+1, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) rmq[0][i] = make_pair(lcp[i], i);
    for (int l = 1; l <= logn; ++l)
      for (int i = 0; i+(1<<l) <= n; ++i)
	rmq[l][i] = min(rmq[l-1][i], rmq[l-1][i+(1<<(l-1))]);
  }
  pair<int, int> rmq_query(int a, int b) {
    int size = b-a+1, l = __lg(size);
    return min(rmq[l][a], rmq[l][b-(1<<l)+1]);
  }
  int get_lcp(int a, int b) {
    if (a == b) return n-a;
    int ia = invsa[a], ib = invsa[b];
    return rmq_query(min(ia, ib)+1, max(ia, ib)).first;
  }
};

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  string s = read_string();
  string t = read_string();
  int t_size = t.size();
  int result = 0;

  vector<int> vi_t(t_size);
  for (int i = 0; i < t_size; ++i)
    vi_t[i] = t[i] - 'a' + 1;
  suffix_array_t sa(vi_t);

  int n0 = count(s.begin(), s.end(), '0');
  int n1 = s.size() - n0;

  for (int s0 = 1; n0 * s0 < t_size; ++s0) {
    if ((t_size - n0 * s0) % n1 != 0) continue;
    int s1 = (t_size - n0 * s0) / n1;

    int last0pos = -1;
    int last1pos = -1;
    int pos = 0;
    bool ok = true;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '0') {
        if (last0pos != -1 && sa.get_lcp(last0pos, pos) < s0) {
          ok = false;
          break;
        }
        last0pos = pos;
        pos += s0;
      } else {
        if (last1pos != -1 && sa.get_lcp(last1pos, pos) < s1) {
          ok = false;
          break;
        }
        last1pos = pos;
        pos += s1;
      }
    }

    if (ok) {
      assert(last0pos != -1);
      assert(last1pos != -1);

      if (s0 == s1 && sa.get_lcp(last0pos, last1pos) >= s0) {
        ok = false;
      }
    }

    if (ok) {
      ++result;
    }
  }
  printf("%d\n", result);

  return 0;
}