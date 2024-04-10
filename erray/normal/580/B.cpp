#include<bits/stdc++.h>
#define pb push_backc
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
ll n, k, a, b;
pair <ll,ll> arr[N];
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;
  for(int i= 0; i < n; i++){
    cin >> arr[i].st  >> arr[i].nd;
  }
  sort(arr , arr + n);
  int p = 0;
  ll sum = 0, ans = -1;
  for(ll i = 0; i< n; i++){
    while(p < n && arr[p].st < arr[i].st + k){
      sum += arr[p++].nd;
    }
    ans = max(ans, sum);
    sum -= arr[i].nd;
  }
  cout << ans;
}