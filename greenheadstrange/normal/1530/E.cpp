// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
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

int n, cnt[30];
char s[maxn];
void solve() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < 26; i++)
    cnt[i] = 0;
  for (int i = 0; i < n; i++)
    cnt[s[i] - 'a']++;
  if (*max_element(cnt, cnt + 26) == n) {
    puts(s);
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 1) {
      printf("%c", i + 'a');
      for (int j = 0; j < 26; j++)
        if (j != i) {
          for (int k = 0; k < cnt[j]; k++)
            printf("%c", j + 'a');
        }
      printf("\n");
      return;
    }
  }
  int first = -1;

  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      first = i;
      break;
    }
  }
  int maj = cnt[first];
  int pre = -1;
  auto print = [&](int x) {
    assert(x >= 0 && x <= 25);
    assert(cnt[x]);
    putchar('a' + x);
    cnt[x]--;
    pre = x;
  };
  if (n - maj >= maj - 2) {
    print(first);
    print(first);
    for (int i = 2; i < n; i++) {
      for (int j = 0; j < 26; j++)
        if (cnt[j] > 0 && (pre != first || j != first)) {
          print(j);
          break;
        }
    }
    printf("\n");
    return;
  }
  int sec = -1;
  for (int i = 0; i < 26; i++)
    if (i != first && cnt[i] && i != first) {
      sec = i;
      break;
    }
  print(first);
  print(sec);
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (cnt[j] == 0)
        continue;
      if (pre == first && j == sec)
        continue;
      if (j == first) {
        if (cnt[first] > 1 && cnt[sec] > 0) {
          bool other = false;
          for (int k = 0; k < 26; k++)
            if (k != first && k != sec && cnt[k]) {
              other = true;
              break;
            }
          if (!other)
            continue;
        }
      }
      print(j);
      break;
    }
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}