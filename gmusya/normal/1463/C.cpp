#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

bool prin(ll l, ll r, ll x) {
  if (l > r)
    swap(l, r);
  return (l <= x && x <= r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  vector <ll> answer;
  while (t--) {
    ll n;
    cin >> n;
    vector <ll> t(n), x(n);
    t.push_back(4e9);
    for (ll i = 0; i < n; i++)
      cin >> t[i] >> x[i];
    ll ans = 0;
    ll last = 0;
    ll curx = 0;
    for (ll i = 0; i < n; i++) {
      if (x[i] == curx) {
        ans++;
        continue;
      }
      ll curt = t[i];
      ll dir = (curx < x[i] ? 1 : -1);
      ll lastt = curt + abs(curx - x[i]);
      ll j = i;
      while (t[j] < lastt)
        j++;
      j--;
      for (ll k = i; k <= j; k++) {
        ll l = curx + (t[k] - t[i]) * dir;
        ll r = curx + (min(t[k + 1], (ll)lastt) - t[i]) * dir;
        ans += prin(l, r, x[k]);
      }
      curx = x[i];
      i = j;
    }
    answer.push_back(ans);
  }
  for (auto &now : answer)
    cout << now << '\n';
  return 0;
}