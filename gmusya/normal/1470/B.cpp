#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

vector <int> sootv;

void init() {
  int MAXN = 1'000'000;
  sootv.resize(MAXN + 1);
  vector <int> lp(MAXN + 1), pr;
  for (int i = 2; i <= MAXN; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && pr[j] * i <= MAXN; j++)
      lp[pr[j] * i] = pr[j];
  }
  for (int i = 1; i <= MAXN; i++) {
    int ci = i;
    ll val = 1;
    while (i > 1) {
      int cnt = 0;
      ll x = lp[i];
      while (i % x == 0) {
        cnt++;
        i /= x;
      }
      if (cnt & 1)
        val *= x;
    }
    i = ci;
    sootv[i] = val;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = sootv[a[i]];
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;
    map <int, int> cnt;
    for (int i = 0; i < n; i++)
      cnt[a[i]]++;
    for (auto &now : cnt) {
      ans1 = max(ans1, now.second);
      if (now.second % 2 == 0 || now.first == 1)
        ans3 += now.second;
      else
        ans2 = max(ans2, now.second);
    }
    int q;
    cin >> q;
    while (q--) {
      ll w;
      cin >> w;
      if (!w)
        cout << ans1 << '\n';
      else
        cout << max(ans2, ans3) << '\n';
    }
  }
  return 0;
}