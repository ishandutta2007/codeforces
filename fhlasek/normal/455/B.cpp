/* Written by Filip Hlasek 2014 */
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

#define MAX_TRIE 222333
int trie[MAX_TRIE][30], T = 1;
bool win[MAX_TRIE], loose[MAX_TRIE];

void dfs(int v) {
  bool end = true;
  REP(i, 26) if (trie[v][i]) {
    dfs(trie[v][i]);
    end = false;
    if (!win[trie[v][i]]) win[v] = true;
    if (!loose[trie[v][i]]) loose[v] = true;
  }
  if (end) loose[v] = true;
}

char word[MAX_TRIE];

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  while (N--) {
    scanf("%s", word);
    int L = strlen(word);
    int t = 0;
    REP(i, L) {
      int l = word[i] - 'a';
      if (trie[t][l] == 0) trie[t][l] = T++;
      t = trie[t][l];
    }
  }
  dfs(0);
  // printf("win: %d loose: %d\n", (int)win[0], (int)loose[0]);
  if (!win[0]) printf("Second\n");
  else if (loose[0]) printf("First\n");
  else {
    if (K % 2) printf("First\n");
    else printf("Second\n");
  }
  return 0;
}