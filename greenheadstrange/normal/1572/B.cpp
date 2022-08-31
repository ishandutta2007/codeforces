// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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

int n, a[maxn];
void solve() {
  scanf("%d", &n);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s ^= a[i];
  }
  if (s == 1) {
    puts("NO");
    return;
  }
  if (n % 2 == 0 && a[1] == 1 && a[n] == 1) {
    bool sm = 1;
    for (int i = 2; i < n; i += 2)
      if (a[i] != a[i + 1]) {
        sm = 0;
        break;
      }
    if (sm) {
      puts("NO");
      return;
    }
  }
  bool isrev = 0;
  vi ans;
  auto add = [&](int x) {
    int c = a[x] ^ a[x + 1] ^ a[x + 2];
    a[x] = a[x + 1] = a[x + 2] = c;
    if (!isrev)
      ans.pb(x);
    else
      ans.pb(n - 1 - x);
  };
  if (a[1] == 1 && a[n] == 1) {
    for (int i = 2; i < n; i += 2)
      if (a[i] != a[i + 1]) {
        for (int j = 1; j < i; j += 2) {
          add(j);
        }
        for (int j = i - 3; j >= 1; j -= 2) {
          add(j);
        }
        break;
      }
    if (a[1] != 0) {
      isrev ^= 1;
      reverse(a + 1, a + n + 1);
      for (int i = 2; i < n; i += 2)
        if (a[i] != a[i + 1]) {
          for (int j = 1; j < i; j += 2) {
            add(j);
          }
          for (int j = i - 3; j >= 1; j -= 2) {
            add(j);
          }
          break;
        }
    }
  }
  if (a[1] != 0) {
    reverse(a + 1, a + n + 1);
    isrev ^= 1;
    assert(a[1] == 0);
  }
  for (int i = 2; i <= n - 1; i++)
    if (a[i] == 1) {
      if (a[i + 1] == 1) {
        add(i - 1);
      } else {
        if (a[i + 2] == 1)
          add(i);
        else {
          add(i);
          add(i - 1);
        }
      }
    }
  for (int i = 1; i <= n; i++)
    assert(a[i] == 0);
  puts("YES");
  printf("%d\n", (int)ans.size());
  for (auto x : ans)
    printf("%d ", x);
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}