/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define L long long

using namespace std;

int Ax,Ay,Bx,By,Cx,Cy;

L det(int a,int b,int c,int d){ return (L)a*d-(L)b*c; }

int gcd(int a,int b){
  if(a==0) return b;
  if(b==0) return a;
  return gcd(b,a%b);
}

bool solve2(int a,int b,int c){
  if(a==0&&b==0) return c==0;
  if(a==0) return c%b==0&&c/b>=0;
  if(b==0) return c%a==0&&c/a>=0;
  int d=gcd(a,b),q;
  if(c%d!=0) return false;
  if(a<0){ c=-c; b=-b; }
  if(b>0) for(q=0;c-b*q>=0;q++) if((c-q*b)%a==0&&(c-q*b)/a>=0) return true;
  else return true;
  return false;
}

bool solve(int a1,int b1,int c1,int a2,int b2,int c2){
  //printf("%d %d %d, %d %d %d\n",a1,b1,c1,a2,b2,c2);
  L D=det(a1,b1,a2,b2),D1=det(a1,c1,a2,c2),D2=det(c1,b1,c2,b2);
  if(D) return (D1%D==0&&D2%D==0&&D1/D>=0&&D2/D>=0);
  return solve2(a1,b1,c1);
}

bool go(int cx,int cy,int dx,int dy){ return solve(cx,dx,Bx-Ax,cy,dy,By-Ay); }

int main(int argc, char *argv[]){
  scanf("%d%d%d%d%d%d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
  int i,j;
  FOR(i,4){
    swap(Ax,Ay);
    Ax=-Ax;
    if(Cx==0&&Cy==0){ if(Ax==Bx&&Ay==By){ printf("YES\n"); return 0; }}
    else{
      FOR(j,4){
        swap(Cx,Cy);
        Cx=-Cx;
        if(go(Cx,Cy,-Cy,Cx)){
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}