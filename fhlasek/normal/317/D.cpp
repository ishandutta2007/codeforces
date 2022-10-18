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

const int sg [] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
set<int> s;

int main(int argc, char *argv[]){
  int N; 
  scanf("%d", &N);
  int g = 0;
  for(int i = 2; (long long)i*i <= N; i++) if(!s.count(i)) {
    int n = 0;
    long long ii = 1;
    while (ii * i <= N) { ii *= i; n++; s.insert(ii); }
    g ^= sg[n];
  }
  g ^= (N - s.size()) % 2;
  if(g) printf("Vasya\n");
  else   printf("Petya\n");
  return 0;
}