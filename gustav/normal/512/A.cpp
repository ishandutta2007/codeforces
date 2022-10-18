#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 105;
const int MAX = 105;

char sol[28];
char s[MAXN][MAX];
int len[MAXN];

enum { WHITE, GRAY, BLACK };

int bio[28];
int mat[28][28];

vector< int > t;

void dfs(int i) {
  bio[i] = GRAY;

  REP(j, 26) {
    if (mat[i][j]) {
      if (bio[j] == GRAY) {
	puts("Impossible");
	exit(0);
      } else if (bio[j] == WHITE) {
	dfs(j);
      }
    } 
  }

  bio[i] = BLACK;
  t.push_back(i);
}

int main(void) 
{
  int n;
  scanf("%d", &n);

  REP(i, n) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }

  REP(i, n - 1) {
    // s[i] < s[i + 1]

    int lcp = 0;
    while (s[i][lcp] == s[i + 1][lcp]) 
      ++lcp;

    if (lcp == min(len[i], len[i + 1])) {
      if (len[i] > len[i + 1]) {
	puts("Impossible");
	exit(0);
      }
    } else {
      mat[s[i][lcp] - 'a'][s[i + 1][lcp] - 'a'] = 1;
      
    }
  }

  REP(i, 26) if (bio[i] == WHITE) dfs(i);
  reverse(t.begin(), t.end());
  for (int i : t) printf("%c", i + 'a');
  puts("");

  return 0;
}