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

using namespace std;

int main(int argc, char *argv[]){
  char rook[5],knight[5];
  int rx,ry,kx,ky;
  scanf("%s",rook);
  scanf("%s",knight);
  rx=rook[0]-'a';
  ry=rook[1]-'1';
  kx=knight[0]-'a';
  ky=knight[1]-'1';
  int x,y,res=0;
  FOR(x,8){
    FOR(y,8){
      if(x==rx||y==ry) continue;
      if(x==kx&&y==ky) continue;

      if(x==kx+2&&y==ky+1) continue;
      if(x==kx+2&&y==ky-1) continue;
      if(x==kx+1&&y==ky+2) continue;
      if(x==kx+1&&y==ky-2) continue;
      if(x==kx-1&&y==ky+2) continue;
      if(x==kx-1&&y==ky-2) continue;
      if(x==kx-2&&y==ky+1) continue;
      if(x==kx-2&&y==ky-1) continue;
      
      if(x==rx+2&&y==ry+1) continue;
      if(x==rx+2&&y==ry-1) continue;
      if(x==rx+1&&y==ry+2) continue;
      if(x==rx+1&&y==ry-2) continue;
      if(x==rx-1&&y==ry+2) continue;
      if(x==rx-1&&y==ry-2) continue;
      if(x==rx-2&&y==ry+1) continue;
      if(x==rx-2&&y==ry-1) continue;

      res++;
    }
  }
  printf("%d\n",res);
  return 0;
}