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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

int a[10];

int main(int argc, char *argv[]){
  int N, x; 
  scanf("%d\n", &N);
  REP(i,N){
    scanf("%d", &x);
    a[x]++;
  }
  bool ok = true;
  if(!a[0]) ok = false;

  int sum = 0;
  REP(i,10) sum += i * a[i];
  
//  printf("%d sum:%d\n",a[0], sum);

  if(sum % 3){
    bool done = false;
    REP(i, 10) if(a[i] && (sum - i) % 3 == 0){ a[i]--; sum -= i; done = true; break; }
    if(!done){
      REP(i, 10){
        if(!a[i]) continue;
        a[i]--;
        REP(j, i+1){
          if(!a[j]) continue;
          a[j]--;
          if((sum - i - j) % 3 == 0){ sum -= i + j; done = true; break; }
          a[j]++;
        }
        if(done) break;
        a[i]++;
      }
    }
    if(!done) ok = false;
  }

  if(sum % 3) ok = false;
  if(!sum) a[0] = 1;
  if(!ok) printf("-1");
  else FORD(d,9,0) REP(i,a[d]) printf("%d",d); 
  printf("\n");
  return 0;
}