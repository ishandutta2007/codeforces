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
#define mid (s + e)/2
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll; 
int n, ip[N], lw[N];
vi pr;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  ip[1] = 1;
  ip[0] = 1;
  for(int i = 2; i <= n; i++){
    if(!ip[i]){
      pr.pb(i);
      lw[i] = i;
      for(int j = i * 2; j <= n; j+= i){
        ip[j] = 1;
        if(lw[j] == 0)lw[j] = i;
      }
    }
  }
  for(int i = 1; i < pr.size() + 1; i++){
    cout << 1 << " ";
  }
  for(int i = 2; i <= n; i++){
    auto it = lower_bound(all(pr), min({n/i, i, lw[i]}));
    int cnt = (it - pr.begin()) + !ip[ min({n/i, i, lw[i]})];
    while(cnt--){
      cout << i << " ";
    }
  }
}