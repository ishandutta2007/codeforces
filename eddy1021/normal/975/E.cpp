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
const int N=20202;
typedef long double type;
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
type norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan(Pt& tp){
  tp.X=getint();
  tp.Y=getint();
}
void print(const Pt& tp){
  printf("(%.6f, %.6f)\n", (double)tp.X, (double)tp.Y);
}
void build(){

}
int n, Q;
Pt p[N], cen, q[N];
void init(){
  n=getint();
  Q=getint();
  for(int i=0; i<n; i++)
    scan(p[i]);
  p[n]=p[0];
  {
    Pt base=p[0];
    for(int i=0; i<=n; i++)
      p[i]=p[i]-base;
    type xsum=0, ysum=0, area=0;
    for(int i=0; i<n; i++){
      type tmp=p[i]^p[i+1];
      xsum+=(p[i].X+p[i+1].X)*tmp;
      ysum+=(p[i].Y+p[i+1].Y)*tmp;
      area+=tmp;
    }
    area*=3.;
    cen={xsum/area, ysum/area};
    cen=cen+base;
    for(int i=0; i<=n; i++)
      p[i]=p[i]+base;
  }
  for(int i=0; i<n; i++)
    q[i]=p[i]-cen;
}
int hang=-1, fixeda=0, fixedb=1;
void stable(int who){
  if(hang==-1 or who==hang) return;
  Pt cur_cen=p[hang]-make_pair(0, norm(q[hang]));
  type nei=(q[who]*q[hang])/norm(q[hang]);
  type wai=(q[who]^q[hang])/norm(q[hang]);
  p[who]=cur_cen+make_pair(wai,nei);
}
void solve(){
  while(Q--){
    int cmd=getint();
    if(cmd==1){
      int f=getint()-1;
      int t=getint()-1;
      if(fixeda==f) swap(fixeda, fixedb);
      stable(fixeda);
      fixedb=t;
      hang=fixeda;
      stable(fixedb);
      continue;
    }
    int asked=getint()-1;
    stable(asked);
    printf("%.12f %.12f\n", (double)p[asked].X, (double)p[asked].Y);
  }
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}