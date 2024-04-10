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

#define MAXN 1111
char s[MAXN];
int N;

int cnt[MAXN];

bool possible(int c) {
  int NN = 0;
  REP(i, 26)  NN += cnt[i] / c + (cnt[i] % c != 0);
  return NN <= N;
}

int main(int argc, char *argv[]){
  scanf("%s", s);
  int S = strlen(s);
  REP(i, S) cnt[s[i] - 'a']++;
  scanf("%d", &N);
  int left = 1, right = S; 
  if(!possible(right)) { printf("-1\n"); return 0; }
  while (left < right) {
    int middle = (left + right) / 2;
    if (possible(middle)) right = middle;
    else left = middle + 1;
  }
  printf("%d\n", left);
  REP(i, 26) {
    int k = cnt[i] / left + (cnt[i] % left != 0);
    REP(j, k) printf("%c", i + 'a');
    N -= k;
  }
  while(N--) printf("a");
  printf("\n");
  return 0;
}