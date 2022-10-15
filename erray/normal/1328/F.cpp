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
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
#define int long long
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, k, x, arr[N];
map <int, int> ct; 
ll t, b, ans = MAX<<32;
 main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    t+= arr[i];
    ct[arr[i]]++;
  }
  set <ll> s; 
  for(int i = 0 ; i< n; i++)for(int j  = -ct[i]; j < ct[i] + 1; j++)if(arr[i] + j >= 0)s.insert((ll)arr[i] + j);
  int bc = 0, tc = n, lst = 0;
  for(auto a : s){
    t -= (a - lst) * tc;
    b += (a - lst) * bc;
    ll nec = k - ct[a];
    if(nec <= 0){
      cout << 0;
      return 0 ;
    }
    if(bc >= nec && tc - ct[a] >= nec){
      if(t - tc + ct[a]> b - bc){
        nec += b - bc;
      }
      else nec += t - tc + ct[a];
    }
    else if(bc >= nec){
      nec += b - bc;
    }
    else if(tc - ct[a] >= nec){
      nec += t - tc + ct[a];
    }
    else {
      nec += t - tc + b - bc + ct[a];
    }
    ans = min(nec, ans);
    bc += ct[a];
    tc -= ct[a];
    lst = a;
  } 
  cout << ans;
}