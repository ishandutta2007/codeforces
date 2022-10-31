#include <bits/stdc++.h>
using namespace std;
#define N 20202
struct Pt{
  int X, Y, c, id;
  bool operator< (const Pt &p) const{
    if( X == p.X ) return Y == p.Y;
    return X < p.X;
  }
  Pt( int _x=0 , int _y=0 , int _c=0 , int _id=0 ){
    X=_x; Y=_y; c=_c; id=_id;
  }
};
int n;
Pt p[ N ], nsp;
bool ptcmp(Pt p1,Pt p2){
  long long x1,x2,y1,y2;
  x1 = p1.X - nsp.X; x2 = p2.X - nsp.X;
  y1 = p1.Y - nsp.Y; y2 = p2.Y - nsp.Y;
  return 1LL*x1*y2<1LL*y1*x2;
}
int ans[ N ];
void meteor(int nl, int nr){
  if(nl == nr) return;
  int t = min_element(p+nl, p+nr) - p;
  swap(p[nl], p[t]);
  nsp = p[nl];
  sort(p+nl+1, p+nr, ptcmp);
  int df = 0, nc = p[nl].c;
  for( int i = nl + 1 ; i < nr ; i ++ ){
    if(p[i].c != nc and df == 0){
      int a = p[nl].id + 1;
      int b = p[i].id + 1;
      ans[min(a, b)] = max(a, b) - n;
      meteor(nl+1, i);
      meteor(i+1, nr);
      return;
    }else
      df += p[i].c;
  }
}
int main(){
  cin >> n;
  for( int i = 0 ; i < n + n ; i ++ ){
    int x , y;
    cin >> x >> y;
    p[ i ] = Pt( x , y , (i < n ? 1 : -1) , i );
  }
  meteor(0, n<<1);
  for( int i = 0 ; i < n ; i ++ )
    printf( "%d\n" , ans[ i + 1 ] );
}