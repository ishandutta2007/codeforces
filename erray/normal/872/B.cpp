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
int n, x, k;
vi v, v2;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;
  int mn = MAX, mx = -MAX;
  for(int i = 0; i < n; i++){ 
    cin >> x;
    mn = min(x, mn);
    mx = max(x, mx);
    v.pb(x);
  }
  if(k == 1){
    cout << mn;
  }
  else if(k == 2){
    int ans = -MAX;
    multiset <int> s1, s2;  
    for(int i = 0; i < v.size(); i++){
      s2.insert(v[i]);
    }
    int num = 0;
    for(auto a : v){
      if(++num == v.size()){
        break;
      }
      auto a2 = s2.find(a);
      s2.erase(a2);
      s1.insert(a);
      ans = max(ans, max(*(s1.begin()), *(s2.begin())));
    }
    cout << ans;
  }
  else {
    cout << mx;
  }
   
  
}