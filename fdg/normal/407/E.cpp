#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct SegmentTree {
  SegmentTree(int _n = 0) : n(_n) {
    tree.assign(4 * n + 2, 0);
    add.assign(4 * n + 2, 0);
  };
  int n;
  vector<long long> tree, add;
  void push(int i) {
    if (i < add.size() && add[i] != 0) {
      if (2 * i < tree.size()) {
        tree[2 * i] += add[i];
        add[2 * i] += add[i];
      }
      if (2 * i + 1 < tree.size()) {
        tree[2 * i + 1] += add[i];
        add[2 * i + 1] += add[i];
      }
      add[i] = 0;
    }
  }
  void update(int i, int L, int R, int l, int r, int val) {
    push(i);
    if (L == l && R == r) {
      add[i] += val;
      tree[i] += val;
      return;
    }
    int m = (L + R) >> 1;
    if (r <= m) update(2 * i, L, m, l, r, val);
    else if (l > m) update(2 * i + 1, m + 1, R, l, r, val);
    else {
      update(2 * i, L, m, l, m, val);
      update(2 * i + 1, m + 1, R, m + 1, r, val);
    }
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }
  int find(int i, int L, int R, int l, int r, int val) {
    // cout << i << "  " <<  L << " " << R << " " << l << " " << r << endl;
    // fflush(stdout);
    push(i);
    if (tree[i] > val) return -1;
    if (L == R) return l;
    int m = (L + R) >> 1;
    if (r <= m) return find(2 * i, L, m, l, r, val);
    else if (l > m) return find(2 * i + 1, m + 1, R, l, r, val);
    int ret = find(2 * i + 1, m + 1, R, m + 1, r, val);
    if (ret == -1) ret = find(2 * i, L, m, l, m, val);
    return ret;
  }
  void output(int i, int l, int r) {
    push(i);
    if (l == r) cout << tree[i] << " ";
    else {
      int m = (l + r) >> 1;
      output(2 * i, l, m);
      output(2 * i + 1, m + 1, r);
    }
  }
};

const int inf = 2000000000;
int arr[200005], nx[200005];
SegmentTree* tree;
int aL = 0, aR = 0;

int solve(int l, int r, int k) {
  bool have = false;
  // cout << l << "  " << r << endl;
  map<int, int> f;
  nx[r] = r + 1; f[arr[r]] = r;
  for (int i = r - 1; i >= l; --i) {
    if (f.count(arr[i])) nx[i] = f[arr[i]];
    else nx[i] = r + 1;
    f[arr[i]] = i;
    nx[i] = min(nx[i], nx[i + 1]);
  }
  int ret = 1;
  vector<pair<int, int> > mnq(1, make_pair(-inf, r + 1)), mxq(1, make_pair(inf, r + 1));
  for (int i = r; i >= l; --i) {
    // tree->update(1, 0, tree->n - 1, i, i, -arr[i]);
    while (mnq.size() > 0 && mnq.back().first > arr[i]) {
      tree->update(1, 0, tree->n - 1, mnq.back().second, mnq[mnq.size() - 2].second - 1, mnq.back().first - arr[i]);
      mnq.pop_back();
    }
    mnq.push_back(make_pair(arr[i], i));
    
    // tree->update(1, 0, tree->n - 1, i, i, arr[i]);
    while (mxq.size() > 0 && mxq.back().first < arr[i]) {
      tree->update(1, 0, tree->n - 1, mxq.back().second, mxq[mxq.size() - 2].second - 1, arr[i] - mxq.back().first);
      mxq.pop_back();
    }
    mxq.push_back(make_pair(arr[i], i));

    if (i != r)
      tree->update(1, 0, tree->n - 1, i + 1, r, -1);

    // tree->output(1, 0, tree->n - 1);
    // cout << endl;

    ret = tree->find(1, 0, tree->n - 1, i, nx[i] - 1, k) - i;
    // cout << tree->find(1, 0, tree->n - 1, i, nx[i] - 1, k) << endl;
    // cout << i << "  " << nx[i] - 1 << "  " << ret + 1 << endl;
    if (ret > aR - aL || ret == aR - aL && have) {
      aL = i; aR = i + ret;
      have = true;
    }
  }
  return ret;
}


int main() {
  // freopen("input.txt", "r", stdin);
  int n, k, d;
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  if (d == 0) {
    int ans = 1, cur = 1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] == arr[i - 1]) ++cur;
      else cur = 1;
      if (cur > aR - aL + 1) {
        aR = i; aL = aR - cur + 1; 
      }
    }
    printf("%d %d\n", aL + 1, aR + 1);
    return 0;
  }
  tree = new SegmentTree(n);
  int ans = 1;
  for (int i = 0; i < n;) {
    int l = i;
    while (i < n && (arr[i] - arr[l]) % d == 0) ++i;
    for (int j = l; j < i; ++j) {
      if (arr[j] >= 0) arr[j] /= d;
      else arr[j] = (arr[j] - (d + (arr[j] % d == 0 ? -d : arr[j] % d))) / d;
      // cout << j << "  " << arr[j] << endl;
    }
    // cout << endl;
    ans = max(ans, solve(l, i - 1, k));
  }
  printf("%d %d\n", aL + 1, aR + 1);
  return 0;
}