#include <bits/stdc++.h>

using namespace std;

void work() {
  int n, q;
  cin >> n >> q;
  std::vector<int> a(n);
  vector<int> up;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > q) {
        up.push_back(i);
    }
  }
  reverse(up.begin(), up.end());
  int low = 0, hig = up.size();
  while (low < hig) {
    int mid = (low + hig + 1) >> 1;
    bool can = true;
    int batas = mid == 0 ? n : up[mid-1];
    int now = q;
    for (int i = 0; i < n; ++i) {
        bool pick = a[i] <= q || i >= batas;
        if (!pick) continue;
        if (now <= 0) {
            can = false;
            break;
        }
        if (a[i] > now) {
            --now;
        }
    }
    if (can)
        low = mid;
    else
        hig = mid - 1;
  }
  string ans(n, '0');
  int batas = low == 0 ? n : up[low-1];
  for (int i = 0; i < n; ++i) {
    if (a[i] <= q || i >= batas) {
        ans[i] = '1';
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; ++t) {
    work();
  }
  return 0;
}