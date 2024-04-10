#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll P = 257;
const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector <ll> p1(1'000'001), p2(1'000'001);
  p1[0] = p2[0] = 1;
  for (int i = 1; i <= 1'000'000; i++) {
    p1[i] = p1[i - 1] * P % MOD1;
    p2[i] = p2[i - 1] * P % MOD2;
  }
  vector <ll> h1(1), h2(1);
  string answer = "";
  for (string tmp : s) {
    int ans = 0;
    ll h1_cur = 0, h2_cur = 0;
    for (int i = 0; i < (int) tmp.size(); i++) {
      if (i + 1 >= h1.size())
        break;
      h1_cur += tmp[i] * p1[i] % MOD1;
      while (h1_cur >= MOD1)
        h1_cur -= MOD1;
      h2_cur += tmp[i] * p2[i] % MOD2;
      while (h2_cur >= MOD2)
        h2_cur -= MOD2;
      bool flag = true;
      {
        ll h_right = h1_cur * p1[h1.size() - i - 1] % MOD1;
        ll h_left = h1.back() - h1[h1.size() - i - 2];
        while (h_left < 0)
          h_left += MOD1;
        flag &= (h_left == h_right);
      }
      {
        ll h_right = h2_cur * p2[h2.size() - i - 1] % MOD2;
        ll h_left = h2.back() - h2[h2.size() - i - 2] % MOD2;
        while (h_left < 0)
          h_left += MOD2;
        flag &= (h_left == h_right);
      }
      if (flag)
        ans = max(ans, i + 1);
    }
    for (int i = ans; i < (int) tmp.size(); i++) {
      answer += tmp[i];
      ll h1_new = h1.back();
      h1_new += tmp[i] * p1[h1.size()] % MOD1;
      while (h1_new >= MOD1)
        h1_new -= MOD1;
      ll h2_new = h2.back();
      h2_new += tmp[i] * p2[h2.size()] % MOD2;
      while (h2_new >= MOD2)
        h2_new -= MOD2;
      h1.push_back(h1_new);
      h2.push_back(h2_new);
    }
  }
  cout << answer;
  return 0;
}