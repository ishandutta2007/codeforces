#include <bits/stdc++.h>

using namespace std;
vector<int> cc;
int n, k;

int query_and(int l, int r) {
#ifdef LOCAL
  return cc[l] & cc[r];
#endif
  printf("and %d %d\n", l+1, r+1);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

int query_or(int l, int r) {
#ifdef LOCAL
  return cc[l] | cc[r];
#endif
  printf("or %d %d\n", l+1, r+1);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

void finish(int x) {
#ifdef LOCAL
  sort(cc.begin(), cc.end());
  assert(x == cc[k]);
#endif
  printf("finish %d\n", x);
  fflush(stdout);
  exit(0);
}

int main() {
  scanf("%d %d", &n, &k);
  --k;
#ifdef LOCAL
  cc.resize(n);
  for (int i = 0; i < n; ++i)
    cc[i] = rand();
#endif
  vector<int> ans(n, 0);
  vector<int> tor, tand;
  for (int i = 0; i < 3; ++i) {
    tor.push_back(query_or(i, (i+1) % 3));
    tand.push_back(query_and(i, (i+1) % 3));
  }
  vector<int> val(3);
  for (int bit = 0; bit <= 30; ++bit) {
    int mask = 1 << bit;
    for (int j = 0; j < 3; ++j) {
      if ((tor[j] & mask) == (mask & tand[j])) {
        int a = j, b = (j + 1) % 3, c = (j + 2) % 3;
        val[a] = val[b] = val[c] = (tor[j] >> bit) & 1;
        if ((tor[b] & mask) != (tand[b] & mask)) {
          val[c] = val[a]^1;
        }
        for (int z = 0; z < 3; ++z) {
          if (!val[z]) continue;
          ans[z] |= mask;
        }
        break;
      }
    }
  }
  for (int i = 3; i < n; ++i) {
    int vand = query_and(0, i);
    int vor = query_or(0, i);
    ans[i] = ans[0] ^ vand ^ vor;
  }
#ifdef LOCAL
  for (int i = 0; i < n; ++i)
    cerr << ans[i] << " " << cc[i] << endl;
  assert(ans == cc);
#endif
  sort(ans.begin(), ans.end());
  finish(ans[k]);
  return 0;
}