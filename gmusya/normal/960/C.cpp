#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ll x, d;
  cin >> x >> d;
  d++;
  vector <ll> ans;
  for (ll pow = 0; (1ll << pow) <= x; pow++)
    if ((1ll << pow) & x) {
      for (int i = 0; i < pow; i++)
        ans.push_back(d * pow * 2);
      ans.push_back(d * pow * 2 + d);
      d++;
    }
  cout << ans.size() << '\n';
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}