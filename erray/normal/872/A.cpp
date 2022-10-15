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
int n, m, x, vis[15];
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  set <int> s, s2, s3; 
  for(int i = 0; i< n; i++){  
    cin >> x;
    vis[x] = 1;
    s.insert(x);
  }
  for(int i = 0; i < m; i++){
      cin >> x;
      if(vis[x])s2.insert(x);
      //vis[x] = 1;
      s3.insert(x);
  }
  if(!s2.empty()){
    cout << *(s2.begin());
  }
  else {
    int a = *(s3.begin()), b = *(s.begin());
    if(a > b)swap(a, b);
    cout << a << b;
  }
}