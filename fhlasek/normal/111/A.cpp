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
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int N,y;
long long x;

int main(int argc, char *argv[]){
  cin >> N >> x >>y; 
  int i;
  if(y>=N&&(long long)(y-N+1)*(y-N+1)>=x-N+1){
    FOR(i,N-1) printf("1\n");
    printf("%d\n",y-N+1);
  }
  else printf("-1\n");
  return 0;
}