// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define FI first
#define SE second
#define PB push_back
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
typedef double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
PII operator-( const PII& p1 , const PII& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
LL operator^( const PII& p1 , const PII& p2 ){
  return (LL)p1.X * p2.Y - (LL)p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
inline void scan( Pt& tp ){
  scanf( "%lf%lf" , &tp.X , &tp.Y );
}
void print( const Pt& tp ){
  printf( "(%.7f, %.7f)" , tp.X , tp.Y );
}
Pt interPnt( Line l1, Line l2, bool &res ){
  Pt p1, p2, q1, q2;
  tie(p1, p2) = l1;
  tie(q1, q2) = l2;
  double f1 = (p2 - p1) ^ (q1 - p1);
  double f2 = (p2 - p1) ^ (p1 - q2);
  double f = (f1 + f2);
  if( fabs(f) < eps)
  { res = false; return {0, 0}; }
  res = true;
  return q1 * (f2 / f) + q2 * (f1 / f);
}
bool isin( Line l0, Line l1, Line l2 ){
  // Check inter(l1, l2) in l0
  bool res;
  Pt p = interPnt(l1, l2, res);
  return ( (l0.SE - l0.FI) ^ (p - l0.FI) ) > eps;
}
/* If no solution, check: 1. ret.size() < 3
 * Or more precisely, 2. interPnt(ret[0], ret[1])
 * in all the lines. (use (l.S - l.F) ^ (p - l.F) > 0
 */
/* --^-- Line.FI --^-- Line.SE --^-- */
vector<Line> halfPlaneInter( vector<Line> lines ){
  int sz = lines.size();
  vector<double> ata(sz), ord(sz);
  for( int i=0; i<sz; i++) {
    ord[i] = i;
    Pt d = lines[i].SE - lines[i].FI;
    ata[i] = atan2(d.Y, d.X);
  }
  sort( ord.begin(), ord.end(), [&](int i, int j) {
    if( fabs(ata[i] - ata[j]) < eps )
      return ( (lines[i].SE - lines[i].FI) ^
               (lines[j].SE - lines[i].FI) ) < 0;
    return ata[i] < ata[j];
  });
  vector<Line> fin;
  for (int i=0; i<sz; i++)
    if (!i or fabs(ata[ord[i]] - ata[ord[i-1]]) > eps)
      fin.PB(lines[ord[i]]);
  deque<Line> dq;
  for (int i=0; i<(int)(fin.size()); i++) {
    while((int)(dq.size()) >= 2 and 
        not isin(fin[i], dq[(int)(dq.size())-2],
                         dq[(int)(dq.size())-1])) 
      dq.pop_back();
    while((int)(dq.size()) >= 2 and 
        not isin(fin[i], dq[0], dq[1]))
      dq.pop_front();
    dq.push_back(fin[i]);
  }
  while( (int)(dq.size()) >= 3 and
      not isin(dq[0], dq[(int)(dq.size())-2],
                      dq[(int)(dq.size())-1]))
    dq.pop_back();
  while( (int)(dq.size()) >= 3 and
      not isin(dq[(int)(dq.size())-1], dq[0], dq[1])) 
    dq.pop_front();
  vector<Line> res(dq.begin(),dq.end());
  return res;
}
void build(){

}
#define N 202020
int n;
vector< pair<int,int> > vv;
pair<int,int> v0;
void init(){
  n = getint();
  v0.X = getint();
  v0.Y = getint();
  vv.resize( n - 1 );
  for( int i = 0 ; i < n - 1 ; i ++ ){
    vv[ i ].X = getint() - v0.X;
    vv[ i ].Y = getint() - v0.Y;
  }
}
int region( pair<int,int> pp ){
  if( ( pp.Y == 0 and pp.X < 0 ) or pp.Y < 0 ) return 0;
  return 1;
}
bool cmp( pair<int,int> p1 , pair<int,int> p2 ){
  if( region( p1 ) != region( p2 ) )
    return region( p1 ) < region( p2 );
  return (LL)p1.X * p2.Y - (LL)p1.Y * p2.X > 0;
}
vector<double> fo;
inline int gcd( int xx , int yy ){
  if( xx == 0 or yy == 0 ) return max( xx , yy );
  return __gcd( xx , yy );
}
void solve(){
  set< pair<int,int> > S;
  for( int i = 0 ; i < n - 1 ; i ++ ){
    int xx = vv[ i ].X;
    int yy = vv[ i ].Y;
    int gg = gcd( abs( xx ) , abs( yy ) );
    if( xx == 0 and yy < 0 ) yy = -yy;
    xx /= gg; yy /= gg;
    if( xx < 0 ) xx = -xx , yy = -yy;
    S.insert( { xx , yy } );
  }
  if( (int)S.size() < n - 1 ){
    fo.push_back( 0. );
    return;
  }
  sort( vv.begin() , vv.end() , cmp );
  for( int i = 0 ; i < n - 1 ; i ++ )
    vv.push_back( vv[ i ] );
  for( int i = 0 ; i < n - 1 ; i ++ )
    vv.push_back( vv[ i ] );
  vector<Line> hf;
  const int inf = 1000000;
/* --^-- Line.FI --^-- Line.SE --^-- */
  hf.push_back( { { -inf , -inf } , { +inf , -inf } } );
  hf.push_back( { { +inf , -inf } , { +inf , +inf } } );
  hf.push_back( { { +inf , +inf } , { -inf , +inf } } );
  hf.push_back( { { -inf , +inf } , { -inf , -inf } } );
  for( int i = 0 ; i < n - 1 ; i ++ )
    if( ( ( vv[ i + 1 ] - vv[ i ] ) ^
             ( make_pair( 0 , 0 ) - vv[ i ] ) ) > 0 )
      hf.push_back( { vv[ i ] + v0 , vv[ i + 1 ] + v0 } );
    else
      hf.push_back( { vv[ i + 1 ] + v0 , vv[ i ] + v0 } );
  for( int i = 0 , iter = 0 ; i < n - 1 ; i ++ ){
    if( iter == i ) iter ++;
    while( ( ( vv[ iter + 1 ] - vv[ i ] ) ^
             ( make_pair( 0 , 0 ) - vv[ i ] ) ) > 0 )
      iter ++;
    if( ( ( vv[ iter ] - vv[ i ] ) ^
             ( make_pair( 0 , 0 ) - vv[ i ] ) ) > 0 )
      hf.push_back( { vv[ i ] + v0 , vv[ iter ] + v0 } );
  }
  vector<Line> ret = halfPlaneInter( hf );
  double ans = 0.0;
  if( ret.size() >= 3u ){
    vector<Pt> rett;
    bool res = true;
    for( size_t i = 0 ; i < ret.size() ; i ++ ){
      rett.push_back( interPnt( ret[ i ] , 
                                ret[ ( i + 1 ) % ret.size() ], res ) );
      if( not res ) break;
    }
    if( res ){
      for( size_t i = 0 ; i < rett.size() ; i ++ )
        ans += rett[ i ] ^ rett[ ( i + 1 ) % rett.size() ];
    }
  } 
  ans *= 0.5;
  fo.push_back( ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    _cs ++;
    init();
    solve();
  }
  for( auto i : fo )
    printf( "%.12f\n" , i );
}