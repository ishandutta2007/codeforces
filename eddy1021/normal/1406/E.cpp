#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int K = 1e5;
constexpr int MAGIC = 317;
constexpr int N = K + 1;
int n, res, total_q;
bool del[N], has_del[N];
LL mpow(LL a, LL b) {
  LL ret = 1;
  while (b --) ret *= a;
  return ret;
}
#ifdef EDDY
constexpr int qN = 1e5;
constexpr int qX = 1;
bool qIn[N];
void prepare() {
  for (int i = 1; i <= qN; ++i) {
    qIn[i] = true;
  }
}
#endif
int go_query(int a) {
  ++total_q;
#ifdef EDDY
  int ret = 0;
  for (int i = a; i <= qN; i += a)
    if (qIn[i]) ++ret;
  return ret;
#else
  printf("A %d\n", a);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
#endif
}
int go_del(int a) {
  assert(a > 1);
  ++total_q;
  if (!has_del[a]) {
    for (int i = a; i <= n; i += a) {
      if (!del[i]) {
        del[i] = true;
        --res;
      }
    }
    has_del[a] = true;
  }
#ifdef EDDY
  int ret = 0;
  for (int i = a; i <= qN; i += a)
    if (qIn[i]){
      ++ret;
      if (i != qX) qIn[i] = false;
    }
  return ret;
#else
  printf("B %d\n", a);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
#endif
}
void answer(int ans) {
  ++total_q;
  fprintf(stderr, "%d querys used\n", total_q);
#ifdef EDDY
  if (ans == qX) {
    puts("Accepted!");
  } else {
    printf("Expected %d, found %d\n", qX, ans);
  }
#else
  printf("C %d\n", ans);
  fflush(stdout);
#endif
}
LL ans = 1;
vector<int> big_p;
int cur;
void gogo(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  int cd = 0;
  for (int i = l; i <= mid; ++i) {
    int ret = go_del(big_p[i]);
    ++ cd;
    if (ret == 2) {
      ans *= big_p[i];
      return;
    }
  }
  int before = cur;
  cur = go_query(1);
  if (cur != before - cd) {
    for (int i = l; i <= mid; ++i) {
      if (go_query(big_p[i]) > 0) {
        ans *= big_p[i];
        return;
      }
    }
    return;
  }
  gogo(mid + 1, r);
}
int main() {
#ifdef EDDY
  n = qN;
  prepare();
#else
  scanf("%d", &n);
#endif
  res = n;
  vector<int> pr;
  for (int i = 2; i <= n and i < MAGIC; ++i) {
    if (del[i]) continue;
    pr.push_back(i);
    go_del(i);
  }
  for (int p: pr) {
    int mx_p = 1;
    while (mpow(p, mx_p) <= n) ++mx_p;
    --mx_p;

    int l = 1, r = mx_p, aa = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int val = mpow(p, mid);
      if (go_query(val) > 0) aa = val, l = mid + 1;
      else r = mid - 1;
    }
    ans *= aa;
  }

  for (int i = MAGIC; i <= n; ++i) {
    if (del[i]) continue;
    big_p.push_back(i);
  }
  cur = go_query(1);
  gogo(0, (int)big_p.size() - 1);
  answer(ans);
}