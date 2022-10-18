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

#define MAXN 2222
char text[MAXN], good[MAXN];
int N, ans = 0;
int trie[1125001][26], T=1;

int main(int argc, char *argv[]){
  scanf("%s", text);
  N = strlen(text);
  scanf("%s", good);
  int K;
  scanf("%d", &K);
  REP(start, N) {
    int k = 0, t = 0;
    FOR(end, start, N-1) {
      int l = text[end] - 'a';
      if(!(good[l]-'0')) k++;
      if(k > K) break;
      if(trie[t][l] == 0) {
        ans++;
        trie[t][l] = T++;
      }
      t = trie[t][l];
    }
  }
  printf("%d\n", ans);
  return 0;
}