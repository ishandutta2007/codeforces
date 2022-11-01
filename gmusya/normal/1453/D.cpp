#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector <ll> ans;

void solve(ll x) {
  if (x % 2)
    return;
  if (!x)
    return;
  ll val = 4;
  int it = 0;
  while (2 * val - 2 <= x)
    val *= 2, it++;
  val -= 2;
  ans.push_back(1);
  while (it--)
    ans.push_back(0);
  solve(x - val);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;
    ans.resize(0);
    solve(k);
    if (ans.empty()) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans.size() << '\n';
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}