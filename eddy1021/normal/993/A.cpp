#include <bits/stdc++.h>
using namespace std;
int x[2][4], y[2][4];
int gcd(int a, int b){
  if(a==0 or b==0) return a+b;
  return __gcd(a, b);
}
bool g(int sx, int sy, int tx, int ty){
  int dx=tx-sx, dy=ty-sy;
  int g=gcd(abs(dx), abs(dy));
  dx/=g; dy/=g;
  while(true){
    if(x[0][0] <= sx and sx <= x[0][3] and
       y[0][0] <= sy and sy <= y[0][3])
      return true;
    if(sx == tx and sy == ty) break;
    sx+=dx; sy+=dy;
  }
  return false;
}
bool f(){
  for(int i=0; i<4; i++)
    for(int j=i+1;j<4;j++)
      if(g(x[1][i], y[1][i],
           x[1][j], y[1][j]))
        return true;
  return false;
}
int main(){
  for(int i=0; i<2; i++)
    for(int j=0; j<4; j++)
      cin>>x[i][j]>>y[i][j];
  sort(x[0], x[0]+4);
  sort(y[0], y[0]+4);
  puts(f()?"YES":"NO");
}