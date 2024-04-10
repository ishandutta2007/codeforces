#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;
const int mod = 998244353;
using ull = uint64_t;
#define endl '\n'
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;

int n;
string k[ms];
string s;

int get(int i) {
  if(i >= (1 << n)) return 1;
  int a = get(i*2);
  int b = get(i*2+1);
  // cout << a << " " << b << " pra " << i << endl;
  int l = i*2, r = i*2+1;
  int ans = a*b;
  // if(i == 1) {
  //   cout << k[l] << " e " << k[r] << endl;
  // }
  if(k[l] != k[r]) {
    ans *= 2;
  }
  ans %= mod;
  k[i].push_back(s[i-1]);
  if(k[l] < k[r]) {
    swap(l, r);
  }
  k[i] += k[l];
  k[i] += k[r];
  return ans;
}

void solve() {
  cin >> n >> s;
  cout << get(1) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    // T++;
    solve(); 
  }
  return 0;
}