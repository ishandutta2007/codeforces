#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(1, vector<int>(n));
  for (int i = 0; i < n; i++)
    cin >> a[0][i];
  long long ansx = 0, ansinv = 0;
  for (int pow = 29; pow >= 0; pow--) {
    vector<vector<int>> b;
    int mod = (1 << pow);
    long long w0 = 0, w1 = 0;
    for (auto &arr : a) {
      vector <int> a0, a1;
      vector <int> cnt(arr.size());
      for (int i = 0; i < (int)arr.size(); i++) {
        bool flag = (arr[i] & mod) > 0;
        if (flag) {
          a1.push_back(arr[i]);
          cnt[i] = 1;
        } else {
          a0.push_back(arr[i]);
          cnt[i] = 0;
        }
      }
      if (!a0.empty())
        b.push_back(a0);
      if (!a1.empty())
        b.push_back(a1);
      vector <int> tmp(arr.size());
      tmp[0] = cnt[0];
      for (int i = 1; i < (int)tmp.size(); i++)
        tmp[i] = tmp[i - 1] + cnt[i];
      for (int i = 0; i < (int)tmp.size(); i++)
        if (!cnt[i])
          w0 += tmp[i];
      tmp[0] = 1 - cnt[0];
      for (int i = 1; i < (int)tmp.size(); i++)
        tmp[i] = tmp[i - 1] + (1 - cnt[i]);
      for (int i = 0; i < (int)tmp.size(); i++)
        if (cnt[i])
          w1 += tmp[i];
    }
    if (w0 <= w1) {
      ansinv += w0;
    } else {
      ansinv += w1;
      ansx += mod;
    }
    swap(a, b);
  }
  cout << ansinv << ' ' << ansx;
  return 0;
}