#include <iostream>
#include <vector>
#include <map>

#define fi first
#define se second

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector <ll> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  map <ll, ll> m;
  for (int i = 0; i < n; i++)
    m[x[i]]++;
  vector <ll> p2(35);
  p2[0] = 1;
  for (int i = 1; i <= 34; i++)
    p2[i] = p2[i - 1] * 2;
  ll ans = 0;
  pair <ll, ll> a = {0, 0};
  pair <ll, ll> b = {0, 0};
  pair <ll, ll> c = {0, 0};
  for (auto &now : m) {
    ll curx = now.fi;
    pair <ll, ll> cura = {now.se, now.fi};
    for (int pow = 0; pow < 33; pow++) {
      pair <ll, ll> curb = {0, 0};
      if (m.find(curx - p2[pow]) != m.end())
        curb = {m[curx - p2[pow]], curx - p2[pow]};
      pair <ll, ll> curc = {0, 0};
      if (m.find(curx + p2[pow]) != m.end())
        curc = {m[curx + p2[pow]], curx + p2[pow]};
      if (cura.fi + curb.fi + curc.fi > ans) {
        ans = cura.fi + curb.fi + curc.fi;
        a = cura, b = curb, c = curc;
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < a.fi; i++)
    cout << a.se << ' ';
  for (int i = 0; i < b.fi; i++)
    cout << b.se << ' ';
  for (int i = 0; i < c.fi; i++)
    cout << c.se << ' ';
  return 0;
}