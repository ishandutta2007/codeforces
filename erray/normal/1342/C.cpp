#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll T, a, b, q, l, r;
void solve(){
  cin >> a >> b >> q;
  int ct = 0;
  vi v;
  v.pb(0);
  ll f = a*b;
  for(ll i = 1; i <= f; ++i){
    if(i%a%b != i%b%a)++ct;
    v.pb(ct);
  }
  while(q--){
    cin >> l >> r;
    ll l2 = l/f*f, r2 = r/f*f;
    cout << (r2-l2)/f*ct + v[r - r2] - v[max(l - l2 - 1, 0)] << " ";
  }
  cout << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> T;
  while(T--)solve();
}