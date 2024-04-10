#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

int n, m, q;
int a[1 << 20];
int b[1 << 20];
int t[1 << 20];

int rev[21];
llint cnt1[21];
llint cnt2[21];

void solve(int l, int r, int n, llint *cnt) {
  if (l + 1 == r) 
    return;

  int m = (l + r) / 2;

  solve(l, m, n - 1, cnt);
  solve(m, r, n - 1, cnt);

  int top = 0;
  int L = l;
  int R = m;

  while (L < m && R < r) {
    if (a[L] <= a[R]) {
      cnt[n] += R - m;
      t[top++] = a[L++];
    } else {
      t[top++] = a[R++];
    }
  }

  while (L < m) {
    cnt[n] += R - m;
    t[top++] = a[L++];
  }

  while (R < r) {
    t[top++] = a[R++];
  }

  for (int i = 0; i < top; ++i)
    a[l + i] = t[i];
}

int main(void)
{
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); ++i)
    scanf("%d", b + i);

  for (int i = 0; i < (1 << n); ++i)
    a[i] = b[i];
  solve(0, (1 << n), n, cnt1);

  for (int i = 0; i < (1 << n); ++i)
    a[i] = b[(1 << n) - 1 - i];
  solve(0, (1 << n), n, cnt2);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q);
    
    for (int j = 1; j <= q; ++j)
      rev[j] ^= 1;

    llint total = 0;
    for (int j = 1; j <= n; ++j) {
      if (rev[j]) {
        total += cnt2[j];
      } else {
        total += cnt1[j];
      }
    }

    cout << total << endl;
  }

  return 0;
}