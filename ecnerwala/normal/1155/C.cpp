#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, M; cin >> N >> M;
  ll X0; cin >> X0;
  ll g = 0;
  for (int i = 1; i < N; i++) {
    ll x; cin >> x;
    g = __gcd(g, x - X0);
  }
  for (int j = 0; j < M; j++) {
    ll p; cin >> p;
    if (g % p == 0) {
      cout << "YES" << '\n' << X0 << ' ' << j+1 << '\n';
      exit(0);
    }
  }
  cout << "NO\n";
  return 0;
}