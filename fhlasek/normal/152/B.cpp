/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int N,M;

bool ok(long long x,long long y){
  return x > 0 && y > 0 && x <= N && y <= M;
}

int main(int argc, char *argv[]){
  int x,y,K,dx,dy;
  long long steps = 0;
  scanf("%d%d",&N,&M);
  scanf("%d%d",&x,&y);
  scanf("%d",&K);
  while(K--){
    scanf("%d%d",&dx,&dy);
    int left = 0, right = 1000000000, middle;
    while(left < right){
      middle = (left+right+1) /2;
      if(ok(x+(long long)middle * dx, y+(long long)middle * dy)) left = middle;
      else right = middle - 1;
    }
    steps += left;
    x += left * dx;
    y += left * dy;
  }
  cout << steps << endl;
  return 0;
}