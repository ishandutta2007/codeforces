// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n2] if
// you want to use magic.
inline LL power(LL x,LL p,LL mod){
	LL s=1,m=x;
	while(p) {
		if(p&1) s=mul(s,m,mod);
		p>>=1;
		m=mul(m,m,mod);
	}
	return s;
}
inline bool witness(LL a,LL n,LL u,int t){
	LL x=power(a,u,n);
	for(int i=0;i<t;i++) {
		LL nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
inline bool miller_rabin(LL n) {
	// iterate s times of witness on n
	// return 1 if prime, 0 otherwise
	if(n<2) return 0;
	if(!(n&1)) return n==2;
	LL u=n-1;
	int t=0;
	// n-1 = u*2^t
	while(!(u&1)) {
		u>>=1;
		t++;
	}
	// while(s--) {
		// LL a=randll()%(n-1)+1;
  LL a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  for( int i = 0 ; i < 7 ; i ++ ){
    if( a[i] > n - 2 ) break;
		if(witness(a[i],n,u,t)) return 0;
	}
	return 1;
}
// does not work when n is prime
inline LL modit(LL x,LL mod) {
	if(x>=mod) x-=mod;
	//if(x<0) x+=mod;
	return x;
}
inline LL mult(LL x,LL y,LL mod) {
	LL s=0,m=x%mod;
	while(y) {
		if(y&1) s=modit(s+m,mod);
		y>>=1;
		m=modit(m+m,mod);
	}
	return s;
}
inline LL f(LL x,LL mod) {
	return modit(mult(x,x,mod)+1,mod);
}
inline LL pollard_rho(LL n) {
	if(!(n&1)) return 2;
  while (true) {
    LL y=2, x=rand()%(n-1)+1, res=1;
    for (int sz=2; res==1; sz*=2) {
      for (int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
#define N 1001
LL n , k , a[ N ] , sa[ N ];
void build(){

}
#define P 215514
bool pr[ P + P ];
vector< LL > p;
void fuck( LL res ){
  if( res == 1 ) return;
  for( LL i = 1 ; i <= n ; i ++ ){
    LL tmp = __gcd( a[ i ] , res );
    if( tmp > 1 && tmp < res ){
      fuck( tmp );
      fuck( res / tmp );
      return;
    }
  }
  p.push_back( res );
}
inline void go(){
  LL tk = k;
  for( int i = 2 ; i < P && tk > 1 ; i ++ ) if( !pr[ i ] ){
    for( int j = P / i ; j >= i ; j -- ) pr[ i * j ] = true;
    if( tk % i == 0 ){
      while( tk % i == 0 ) tk /= i;
      p.push_back( i );
    }
  }
  fuck( tk );
  sort( p.begin() , p.end() );
  p.resize( unique( p.begin() , p.end() ) - p.begin() );
}
vector< int > fc;
inline void go_fac(){
  LL tmp = a[ 0 ];
  for( LL vl : p ){
    int cnt = 0;
    while( tmp % vl == 0 )
      cnt ++, tmp /= vl;
    fc.push_back( cnt );
  }
}
unordered_map< LL , int > hsh;
vector< LL > tb;
inline void gogo( int now , LL ret ){
  if( now == (int)p.size() ){
    tb.push_back( ret );
    return;
  }
  for( int i = 0 ; i <= fc[ now ] ; i ++ ){
    gogo( now + 1 , ret );
    ret *= p[ now ];
  }
}
int pcnt;
inline void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    sa[ i ] = getint();
    a[ i ] = __gcd( sa[ i ] , k );
  }
  sa[ 0 ] = a[ 0 ] = k;
  go();
  go_fac();
  gogo( 0 , 1 );
  sort( tb.begin() , tb.end() );
  pcnt = 0;
  for( auto i : tb )
    hsh[ i ] = pcnt ++;
}
pair<int,ULL> dp[ 1 << 20 ];
vector<int> ans[ 1 << 20 ];
inline void find_ans(){
  // int now = hsh[ k ];
  // vector< int > ans;
  // while( now ){
    // ans.push_back( who[ now ] );
    // now = bk[ now ];
  // }
  vector<int>& fans = ans[ hsh[ k ] ];
  sort( ALL( fans ) );
  printf( "%d\n" , (int)fans.size() );
  for( size_t i = 0 ; i < fans.size() ; i ++ )
    printf( "%d%c" , fans[ i ] , " \n"[ i + 1 == fans.size() ] );
}
void solve(){
  if( k == 1 ){
    int bst = 1;
    for( int i = 2 ; i <= n ; i ++ )
      if( sa[ i ] < sa[ bst ] )
        bst = i;
    printf( "1\n%d\n" , bst );
    exit( 0 );
  }
  for( int i = 0 ; i < pcnt ; i ++ )
    dp[ i ] = { n + n , 0 };
  dp[ 0 ] = { 0 , 0 };
  for( int i = 1 ; i <= n ; i ++ ){
    if( a[ i ] == 1 ) continue;
    for( int j = pcnt - 1 ; j >= 0 ; j -- ){
      if( dp[ j ].FI > n ) continue;
      LL mr = k / tb[ j ];
      LL got = __gcd( mr , a[ i ] );
      mr = tb[ j ] * got;
      int idx = hsh[ mr ];
      pair<int,ULL> tsum = { dp[ j ].FI + 1 , dp[ j ].SE + sa[ i ] };
      if( tsum < dp[ idx ] ){
        dp[ idx ] = tsum;
        ans[ idx ] = ans[ j ];
        ans[ idx ].push_back( i );
      }
    }
  }
  if( dp[ hsh[ k ] ].FI <= n ) find_ans();  
  else puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}