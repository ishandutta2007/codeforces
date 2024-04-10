#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int BS = 555;
int arr[100005];

struct query {
  int l, r, id;
};

bool operator < (const query &a, const query &b) {
  return a.l / BS < b.l / BS || a.l / BS == b.l / BS && a.r < b.r;
}

int cnt[2000001];
long long ans[100001];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    arr[i] ^= arr[i - 1];
  }

  vector<query> q;
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    q.push_back(query{l, r, i});
  }
  sort(q.begin(), q.end());

  for (int i = 0; i < q.size(); ++i) {
    int l = q[i].l, r = l - 1;
    long long cur = 0;
    while (r < q[i].r) {
      cur += cnt[arr[r] ^ k];
      cnt[arr[r]]++;
      ++r;
    }
    ans[q[i].id] += cur + cnt[arr[r] ^ k];
    while (i + 1 < q.size() && q[i + 1].l / BS == q[i].l / BS) {
      ++i;
      while (l < q[i].l) {
        --cnt[arr[l - 1]];
        cur -= cnt[arr[l - 1] ^ k];
        ++l;
      }
      while (l > q[i].l) {
        --l;
        cur += cnt[arr[l - 1] ^ k];
        ++cnt[arr[l - 1]];
      }
      while (r < q[i].r) {
        cur += cnt[arr[r] ^ k];
        cnt[arr[r]]++;
        ++r;
      }
      // cout << l << "  " << r << " " << q[i].l << "  " << q[i].r << endl;
      ans[q[i].id] += cur + cnt[arr[r] ^ k];
    }
    for (int j = l - 1; j < r; ++j)
      cnt[arr[j]]--;
  }

  for (int i = 0; i < m; ++i) {
    printf("%lld\n", ans[i]);
  }

  return 0;
}