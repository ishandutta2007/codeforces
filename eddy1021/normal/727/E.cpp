#include <bits/stdc++.h>
using namespace std;
#define N 2020202
typedef long long LL;
const LL BS = 13131LL;
const LL mod1 = 1000000007LL;
const LL mod2 = 1000000009LL;
inline int add(int a, int b, int mod){
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod){
  a -= b;
  return a < 0 ? a + mod : a;
}
inline LL mul(LL a, LL b, LL mod){
  a *= b;
  return a >= mod ? a % mod : a;
}
int n, k, hs1[N], hs2[N];
char c[N];
map<LL,int> M;
void init(){
  scanf( "%d%d" , &n , &k );
  scanf( "%s" , c + 1 );
  for(int i = n*k + 1 ; i <= 2 * n * k ; i ++)
    c[i] = c[i-n*k];
  for(int i = 1 ; i <= 2 * n * k ; i ++)
    hs1[i] = add(mul(hs1[i-1], BS, mod1), c[i], mod1);
  for(int i = 1 ; i <= 2 * n * k ; i ++)
    hs2[i] = add(mul(hs2[i-1], BS, mod2), c[i], mod2);
  int x; scanf( "%d" , &x );
  for(int i = 1 ; i <= x ; i ++){
    scanf( "%s" , c );
    int vl1 = 0 , vl2 = 0;
    for(int j = 0 ; j < k ; j ++){
      vl1 = add(mul(vl1, BS, mod1), c[j], mod1);
      vl2 = add(mul(vl2, BS, mod2), c[j], mod2);
    }
    LL vl = (LL)vl1 + (LL)vl2 * mod2;
    //assert(M.find(vl) == M.end());
    M[vl] = i;
  }
}
int who[N];
set<int> cnt[N];
void go( int st ){
  vector<int> ans;
  for( int i = st ; i <= n * k ; i += k )
    ans.push_back(who[i]);
  puts( "YES" );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
  exit(0);
}
void solve(){
  int bs1 = 1, bs2 = 1;
  for( int i = 0 ; i < k ; i ++ ){
    bs1 = mul(bs1, BS, mod1);
    bs2 = mul(bs2, BS, mod2);
  }
  for( int i = 1 ; i <= n * k ; i ++ ){
    int tvl1 = sub(hs1[i+k-1], mul(hs1[i-1], bs1, mod1), mod1);
    int tvl2 = sub(hs2[i+k-1], mul(hs2[i-1], bs2, mod2), mod2);
    LL tvl = (LL)tvl1 + (LL)tvl2 * mod2;
    auto it = M.find(tvl);
    if( it != M.end() ){
      cnt[i%k].insert(it->second);
      who[i] = it->second;
    }
  }
  for( int i = 0 ; i < k ; i ++ )
    if( (int)cnt[ i ].size() == n )
      go(i == 0 ? k : i);
  puts( "NO" );
}
int main(){
  init();
  solve();
}