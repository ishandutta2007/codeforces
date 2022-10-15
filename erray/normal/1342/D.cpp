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
int n, k;
void solve(){
  cin >> n >> k;
  vi m(n), c(k + 1);
  for(int i = 0; i < n; ++i)cin >> m[i];
  for(int i = 0; i < k; ++i)cin >> c[i + 1];
  sort(all(m), greater <int>());
  multiset <int> s; 
  for(int a : m){
    if(s.empty() || *s.begin() + 1 > c[a])s.insert(1);
    else{
      s.insert(*s.begin() + 1);
      s.erase(s.begin());
    }
  }
  cout << s.size() << ln;
  vi ans[s.size()];
  for(int i = 0; i < n; ++i)ans[i%s.size()].pb(m[i]);
  for(int i = 0; i < s.size(); ++i){
    cout << ans[i].size() << " ";
    for(int a : ans[i])cout << a << " ";
    cout << ln;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}