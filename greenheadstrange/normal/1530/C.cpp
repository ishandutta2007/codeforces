// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, m;
struct score {
  multiset<int> s, t;
  int score;
  int cnt;
  void init() {
    s.clear();
    t.clear();
    score = cnt = 0;
  }
  void add(int x) {
    cnt += 1;
    if (t.empty() || x >= *t.rbegin()) {
      s.insert(x);
      score += x;
    } else {
      t.insert(x);
    }
    if (t.size() < cnt / 4) {
      int x = *s.begin();
      s.erase(s.begin());
      t.insert(x);
      score -= x;
    }
    if (t.size() > cnt / 4) {
      int x = *t.rbegin();
      t.erase(--t.end());
      s.insert(x);
      score += x;
    }
  }
} A, B;
void solve() {
  scanf("%d", &n);
  A.init();
  B.init();
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    A.add(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    B.add(x);
  }
  int extra = 0;
  while (A.score < B.score) {
    A.add(100);
    B.add(0);
    extra++;
  }
  printf("%d\n", extra);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}