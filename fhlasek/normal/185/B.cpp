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

int main(int argc, char *argv[]){
  int S;
  long long a,b,c,s;
  cin >> S >> a >> b >> c;
  s = a + b + c;
  if(!s){
    printf("%lf %lf %lf\n",0.0,0.0,0.0);
    return 0;
  }
  printf("%.15lf %.15lf %.15lf\n",(double)a/s*S,(double)b/s*S,(double)c/s*S);
  return 0;
}