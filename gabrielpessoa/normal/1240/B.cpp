#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int arr[ms];
int bnd[ms];
map<int, int> dic;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    dic.clear();
    for(int i = 1; i <= n; i++) {
      cin >> arr[i];
      dic[arr[i]] = 1;
    }
    int k = 0;
    for(auto &e : dic) {
      e.second = ++k;
      bnd[k] = inf;
    }
    set<int> p;
    p.insert(k+1);
    bnd[k+1] = k+1;
    for(int i = 1; i <= n; i++) {
      arr[i] = dic[arr[i]];
      int x = *p.upper_bound(arr[i]);
      // cout << i << ' ' << arr[i] << ' ' <<x << " socorro" << endl;
      bnd[arr[i]] = min(x, bnd[arr[i]]);
      p.insert(arr[i]);
    }
    for(int i = k-1; i > 0; i--) {
      bnd[i] = min(bnd[i], bnd[i+1]);
    }
    // for(int i = 1; i <= n; i++) {
    //   if(!frst[dic[arr[i]]]) frst[dic[arr[i]]] = i;
    //   lst[dic[arr[i]]] = i;
    // }
    // for(int i = 2; i <= k; i++) {
    //   lst[i] = max(lst[i], lst[i-1]);
    // }
    // lst[0] = 0;
    // for(int i = k-1; i >= 1; i--) {
    //   frst[i] = min(frst[i], frst[i+1]);
    // }
    // frst[k+1] = n+1;
    int ans = inf;
    for(int i = 0; i <= k; i++) {
      int cur = i + (k+1 - bnd[i+1]);
      // cout << i << ' ' << k << ' ' << bnd[i+1] << endl;
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}