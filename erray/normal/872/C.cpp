#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, x; 
void solve(){
  cin >> x;
  if(x < 4){cout << -1 << ln;return;}
  int ans = x / 4;
  if(x % 4 == 3){
    if(x < 15){
        cout << -1 << ln;
        return;
    }
    ans -= 1;
  }
  else if(x % 4 == 1){
    if(x < 9){
      cout << -1 << ln;
      return;
    }
    ans  -= 1;
  }
  cout << ans << ln;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  while(n--){
    solve();
  }
}