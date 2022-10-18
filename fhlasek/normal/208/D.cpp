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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 5555
int p[MAXN];
int a[10];
long long ans[10];

int main(int argc, char *argv[]){
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", p + i);
  REP(i, 5) scanf("%d", a + i);
  int sum = 0;
  REP(i, N){
    sum += p[i];
    FORD(j,4,0){
      int add = sum / a[j];
      ans[j] += add;
      sum -= add * a[j];
    }
  }
  REP(i, 5){
    if(i) cout << " ";
    cout << ans[i];
  }
  cout << endl << sum << endl;
  return 0;
}