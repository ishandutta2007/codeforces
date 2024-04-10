// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
typedef LL type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Seg;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define A first
#define B second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
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
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan(Pt& p){
  p.X=getint();
  p.Y=getint();
}
LL ori( const Pt& o , const Pt& a , const Pt& b ){
  LL ret = ( a - o ) ^ ( b - o );
  return (ret > 0) - (ret < 0);
}
// p1 == p2 || q1 == q2 need to be handled
bool banana( const Pt& p1 , const Pt& p2 ,
             const Pt& q1 , const Pt& q2 ){
  if( ( ( p2 - p1 ) ^ ( q2 - q1 ) ) == 0 ){ // parallel
    return false;
  }
  return (ori( p1, p2, q1 ) * ori( p1, p2, q2 )<=0) &&
         (ori( q1, q2, p1 ) * ori( q1, q2, p2 )<=0);
}
Pt interPnt( Pt p1, Pt p2, Pt q1, Pt q2, bool& res){
  if(not banana(p1, p2, q1, q2)){
    res=false;
    return {0, 0};
  }
	LL f1 = ( p2 - p1 ) ^ ( q1 - p1 );
	LL f2 = ( p2 - p1 ) ^ ( p1 - q2 );
	LL f = ( f1 + f2 );
	if(f == 0){
    res=false;
    return {0, 0};
  }
  LL rx=q1.X*f2+q2.X*f1;
  LL ry=q1.Y*f2+q2.Y*f1;
  if(rx % f or ry % f){
    res=false;
    return {0, 0};
  }
  res=true;
  rx/=f;
  ry/=f;
  return {rx, ry};
}
void build(){

}
const int N=1021;
int n;
Seg s[N];
LL ans;
LL gcd(LL a, LL b){
  if(a and b) return __gcd(a, b);
  return a+b;
}
set<pair<LL,LL>> tot;
set<pair<LL,LL>> on[N];
void init(){
  n=getint();
  for(int i=0; i<n; i++){
    scan(s[i].A);
    scan(s[i].B);
    LL dx=abs(s[i].B.X-s[i].A.X);
    LL dy=abs(s[i].B.Y-s[i].A.Y);
    LL gg=gcd(dx, dy);
    ans+=gg+1;
  }
}
void solve(){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      if(i == j) continue;
      bool r=false;
      Pt ret=interPnt(s[i].A, s[i].B, s[j].A, s[j].B, r);
      if(not r) continue;
      tot.insert(ret);
      on[i].insert(ret);
    }
  for(int i=0; i<n; i++)
    ans-=on[i].size();
  ans+=tot.size();
  printf("%lld\n", ans);
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}