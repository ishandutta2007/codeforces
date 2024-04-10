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

int N;
char line[55];

int main(int argc, char *argv[]){
  scanf("%d", &N);
  scanf("%s", line);
  int pos = 0, ans = 0;
  while(pos < N){
    int i = pos;
    while(i < N && line[i] == line[pos]) i++;
    ans += i - pos - 1;
    pos = i;
  }

  printf("%d\n", ans);
   
  return 0;
}