/* Written by Filip Hlasek 2013 */
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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

bool distinct(int Y){
  set<int> s;
  while(Y){
    if(s.count(Y%10)) return false;
    s.insert(Y%10);
    Y/=10;
  }
  return true;
}

int main(int argc, char *argv[]){
  int Y; 
  scanf("%d", &Y);
  while(true){
    if(distinct(++Y)){
      printf("%d\n", Y);
      break;
    }
  }
  return 0;
}