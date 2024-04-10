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

#define MAXN 111111
int a[MAXN], b[MAXN], N, MOD;
vector<pair<int, int> > v;

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) scanf("%d", b + i);
  scanf("%d", &MOD);
  REP(i, N){
    v.push_back(make_pair(a[i], i));
    v.push_back(make_pair(b[i], i));
  }
  sort(v.begin(), v.end());
  int start = 0, ans = 1;
  while(start < 2*N) {
    int end = start;
    while(end < 2*N && v[end].first == v[start].first) end++;
    while(start < end) {
      if(start + 1 < end && v[start] == v[start + 1]) {
        ans = ((long long)ans * (((long long)(end-start) * (end-start-1) / 2) % MOD)) % MOD;
        start += 2;
      }
      else{
        ans = ((long long)ans * (end - start)) % MOD;
        start++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}