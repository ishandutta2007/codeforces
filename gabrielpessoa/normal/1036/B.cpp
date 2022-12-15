#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 5e5+5;
int a[ms];

int main() {
  int q;
  cin >> q;
  while(q--) {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = k;
    ll distancia = max(n, m);
    if(distancia > k) {
      cout << -1 << endl;
    } else if((n + m) % 2 == 0) {
      ll resto = k - distancia;
      //cout << resto << endl;
      if(resto % 2 == 0) {
        cout << ans << endl;
      } else {
        cout << ans - 2 << endl;
      }
    } else {
      cout << ans - 1 << endl;
    }
  }
  return 0;
}