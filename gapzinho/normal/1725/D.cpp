#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 1e6+5;
const int mod = 998244353;


int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return ans;
}


ordered_set X;
int valor[ms];
  int cur = 0, limCur = 0;

  priority_queue<ii, vector<ii>, greater<ii>> pq;
  int qntrem = 0;
  int delta;


void updaterem() {
  delta += X.size();
  qntrem++;
  while(!pq.empty() && pq.top().first <= qntrem) {
    int x = pq.top().second;
    pq.pop();
    if(valor[x] + qntrem == cur && (int) X.size() <= limCur) {
      pq.emplace(qntrem+1, x);
      continue;
    }
    X.erase(x);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  int cnt = 0;
  int sum = 0;
  vector<ii> vec;
  for(int id = 1; cnt < n; id++) {
    int gt = min(n-cnt, (id+1)/2);
    cnt += gt;
    cur = id;
    limCur = gt;
    sum += gt * id;
    // for(int y = 0; y < gt; y++) {
    //   int x = (id+1)/2 - y - 1;
    //   int val = id % 2 ? ((id-x-x) << (x+x)) : ((id-1-x-x) << (x+x+1));
    //   // cout << val << " - " << id << ", " << x << endl;
    //   vec.emplace_back(val, id);
    // }
  }
  cout << sum << endl;
  // cout << cur << " - " << limCur << endl;
  // sort(vec.begin(), vec.end());
  if(limCur == (cur+1)/2) {
    limCur = 0;
    cur++;
  }
  vector<int> v;
  for(int i = 1; i < cur; i++) {
    int x = i;
    int cnt2 = 0;
    while(x % 2 == 0) {
      cnt2++;
      x /= 2;
    }
    x += cnt2;
    v.emplace_back(x);
  }


  // X.insert(1); X.find_by_order(0);
  // X.order_of_key(-5); end(X), begin(X);

  for(int i = (cur+1)/2; i < cur; i++) {
    X.insert(i);
    valor[i] = v[i-1];
    // cout << valor[i] << "- ";
    pq.emplace(cur - valor[i], i);
  }
  // cout << v[1] << endl;
  updaterem();
  delta = cur;
  while(q--) {
    int x;
    cin >> x;
    int ans;
    if(x < cur) {
      ans = v[x-1];
      cout << ans << '\n';
      continue;
    }
    while(x >= delta + (int) X.size()) {
      // cout << "atualizando " << endl;
      updaterem();
    }
    // cout << x-delta << " - " << endl;
    auto val = *X.find_by_order(x-delta);
    ans = valor[val] + qntrem;
    // cout << valor[val] << endl;
    cout << ans << '\n';
    // cout << ans << " - " << vec[x-1].second << endl;
    
    // assert(vec[x-1].second == ans);
  }
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}