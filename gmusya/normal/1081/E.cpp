#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector <int> x(n / 2);
  for (int i = 0; i < n / 2; i++)
    cin >> x[i];
  ll old = 0;
  vector <ll> ans;
  for (int v : x) {
    ll b_ans = INF;
    for (ll i = 1; i * i <= v; i++) {
      if (v % i)
        continue;
      if ((i + v / i) % 2)
        continue;
      ll a = (i + v / i) / 2;
      ll b = a - i;
      if (b <= old)
        continue;
      b_ans = min(b, b_ans);
    }
    if (b_ans == INF) {
      cout << "No\n";
      return 0;
    }
    ll new_old = round(sqrt(old * old + b_ans * b_ans - old * old + v));
    ans.push_back( b_ans * b_ans - old * old);
    ans.push_back(v);
    old = new_old;
  }
  cout << "Yes\n";
  for (ll v : ans)
    cout << v << ' ';
  return 0;
}