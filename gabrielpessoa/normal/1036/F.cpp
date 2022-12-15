#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e6+5;
const ll inf = 2e18;

vector<ll> ans[60];
ll primes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int sz = 16;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  for(int i = 0; i < sz; i++) {
    bool overflow = false;
    for(ll j = 2; !overflow ; j++) {
      ll raiz = floor(sqrt(j));
      if(raiz * raiz == j) continue;
      //if(i == 0 && j == 4) cout << "oi" << endl;
      ll temp = 1;
      for(int k = 0; k < primes[i] && !overflow; k++) {
        if(temp  > 2e18/j) {
          overflow = true;
        } else {
          temp = temp * j;
        }
      }
      if(!overflow) {
        bool achou = false;
        //cout << temp << endl;
        for(int k = 0; k < i; k++) {
          if(*lower_bound(ans[k].begin(), ans[k].end(), temp) == temp) achou = true;
        }
        if(!achou) ans[i].push_back(temp); //[z[i]++] = temp;
      }
    }
    ans[i].push_back(inf);
  }
  //cout << "fim" << endl;
  int t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    ll r = floor(sqrt((long double) n));
   // cout << r << endl;
    for(int i = 0; i < sz; i++) {
      ll temp = (upper_bound(ans[i].begin(), ans[i].end(), n) - ans[i].begin());
      r += temp;
      //if(temp) cout << i << ' ' << temp << endl;
    }
    cout << n - r << endl;

  }
  return 0;
}