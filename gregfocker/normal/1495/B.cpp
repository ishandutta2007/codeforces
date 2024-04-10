#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n, a[N], tolx[N], torx[N], toly[N], tory[N];

bool good(int x, int y) {
  int turn = 1;
  /// turn = 0 => x plays, turn = 1 => y plays
  if (x < y) {
    int variant_x = tolx[x], variant_y;
    int best_y = max(tory[y], toly[y]);
    if (variant_x > best_y) {
      return 1;
    }
    if (x % 2 == y % 2) {
      variant_x = torx[x];
      variant_y = tory[y];
      if (variant_x > variant_y) {
        return 1;
      }
    }
  } else {
    int variant_x = torx[x], variant_y;
    int best_y = max(tory[y], toly[y]);
    if (variant_x > best_y) {
      return 1;
    }
    if (x % 2 == y % 2) {
      variant_x = tolx[x];
      variant_y = toly[y];
      if (variant_x > variant_y) {
        return 1;
      }
    }
  }
  return 0;
}

vector<int> by1, by2;

bool cmpy1(int i, int j) {
  return tory[i] > tory[j];
}

bool cmpy2(int i, int j) {
  return toly[i] > toly[j];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  /// x
  for (int i = 2; i <= n; i++) if (a[i - 1] < a[i]) tolx[i] = 1 + tolx[i - 1];
  for (int i = n - 1; i >= 1; i--) if (a[i + 1] < a[i]) torx[i] = 1 + torx[i + 1];
  /// y
  for (int i = 2; i <= n; i++) if (a[i - 1] > a[i]) toly[i] = 1 + toly[i - 1];
  for (int i = n - 1; i >= 1; i--) if (a[i + 1] > a[i]) tory[i] = 1 + tory[i + 1];

  for (int i = 1; i <= n; i++) by1.push_back(i);
  by2 = by1;
  sort(by1.begin(), by1.end(), cmpy1);
  sort(by2.begin(), by2.end(), cmpy2);

  int ret = 0;
  for (int x = 2; x < n; x++) {
    if (a[x] > a[x - 1] && a[x] > a[x + 1]) {
      //cout << " : " << x << "\n";
      bool ok = 1;
      int lim = min(15LL, n);
      for (int i = 0; i < lim; i++) ok &= (good(x, by1[i]));
      for (int i = 0; i < lim; i++) ok &= (good(x, by2[i]));
      if (ok) ret++;
    }
  }
  cout << ret << "\n";
}