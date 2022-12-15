#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int arr[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    for(int i= 1; i <= n; i++) {
      cin >> arr[i];
      arr[i] /= 100;
    }
    sort(arr+1, arr+n+1);
    reverse(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++) {
      arr[i] += arr[i-1];
      // cout << arr[i] << endl;
    }
    int x, y, a, b;
    cin >> x >> a >> y >> b;
    if(y > x) {
      swap(x, y);
      swap(a, b);
    }
    int k;
    cin >> k;
    int lo = 1, hi = n+1;
    int p = a * b /__gcd(a, b);
    while(lo < hi) {
      int mi = (lo+hi)/2;
      int qnt = mi/p;
      int ans = arr[qnt] * (x+y) + (arr[mi/a] - arr[qnt]) * x + (arr[mi/b-qnt+mi/a] - arr[mi/a]) * y;
      // cout << arr[mi/(a+b)] << ' ' << (arr[mi/a] - arr[qnt]) << ' '  << (arr[mi/b-qnt+mi/a] - arr[mi/a])  << endl;
      // cout << mi << ' ' << ans << ' ' << mi/(a+b) << endl;
      if(ans >= k) hi = mi;
      else lo = mi +1;
    }
    if(lo <= n) cout << lo << '\n';
    else cout << -1 << '\n';
  }
}