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

#define MAXN 111111
int a[MAXN],N;
stack<int> s;

int main(int argc, char *argv[]){
  int ans = 0;
  scanf("%d",&N);   
  REP(i,N) scanf("%d",a+i);
  ans = a[0];
  REP(i,N-1) if(a[i+1] > a[i]) ans += a[i+1] - a[i];
  printf("%d\n",ans);
  int last = 0;
  REP(i,N+1){
    if(a[i] < last){
      REP(j,last-a[i]){
        printf("%d %d\n",s.top(),i);
        s.pop();
      }
    }
    else REP(j,a[i]-last) s.push(i+1);
    last = a[i];
  }
  return 0;
}