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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

bool done[5555];

int main(int argc, char *argv[]){
  int N,res=0,a; 
  scanf("%d",&N);
  REP(i,N){
    scanf("%d",&a);
    if(done[a]||a>N) res++;
    done[a]=true;
  }
  printf("%d\n",res);
  return 0;
}