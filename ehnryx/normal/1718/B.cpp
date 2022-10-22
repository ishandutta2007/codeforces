#include <bits/stdc++.h>
using namespace std;

//%:include "utility/defines.h"
//%:include "utility/fast_input.h"
//%:include "utility/output.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    vector<ll> fib;
    ll fsum = 0;
    for(ll i=1, j=0; fsum < sum; ) {
      ll k = i + j;
      fib.push_back(k);
      fsum += k;
      i = j;
      j = k;
    }
    if(fsum != sum) {
      cout << "NO" << nl;
      continue;
    }

    reverse(begin(fib), end(fib));
    priority_queue<int> have(begin(a), end(a));
    int add = 0;
    for(ll f : fib) {
      if(have.empty() || have.top() < f) {
        break;
      }
      int x = have.top();
      have.pop();
      if(add) {
        have.push(add);
      }
      add = x - f;
    }

    if(have.empty() && add == 0) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}