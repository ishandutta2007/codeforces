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
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int N;
int a[MAXN];

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  int M;
  long long last = 0;
  scanf("%d", &M);
  while(M--) {
    int w, h;
    scanf("%d%d", &w, &h);
    last = max(last, (long long)a[w-1]);
    cout << last << endl;
    last += h;
  }
   
  return 0;
}