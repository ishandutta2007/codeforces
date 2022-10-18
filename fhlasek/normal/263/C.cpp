/* Written by Filip Hlasek 2012 */
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
int a[2*MAXN], b[2*MAXN];
int nb[MAXN][4], NB[MAXN];
int N;
int ans[MAXN], A = 0;
bool used[MAXN];

bool edge(int a, int b){
  REP(i, 4) if(nb[a][i] == b) return true;
  return false;
}

bool good(int a, int b, int c, int d){ return edge(a, b) && edge(b, c) && edge(c, d); }

bool solve(){
  REP(i, 2*N){
    if(NB[a[i]] == 4 || NB[b[i]] == 4) return false;
    nb[a[i]][NB[a[i]]++] = b[i];
    nb[b[i]][NB[b[i]]++] = a[i];
  }
  ans[A++] = 0;
  if(good(nb[0][0], nb[0][1], nb[0][2], nb[0][3])){ ans[A++] = nb[0][2]; ans[A++] = nb[0][3]; }
  else if(good(nb[0][1], nb[0][0], nb[0][2], nb[0][3])){ ans[A++] = nb[0][2]; ans[A++] = nb[0][3]; }
  else if(good(nb[0][1], nb[0][0], nb[0][3], nb[0][2])){ ans[A++] = nb[0][3]; ans[A++] = nb[0][2]; }
  else if(good(nb[0][0], nb[0][1], nb[0][3], nb[0][2])){ ans[A++] = nb[0][3]; ans[A++] = nb[0][2]; }
  else if(good(nb[0][0], nb[0][3], nb[0][1], nb[0][2])){ ans[A++] = nb[0][1]; ans[A++] = nb[0][2]; }
  else if(good(nb[0][3], nb[0][0], nb[0][1], nb[0][2])){ ans[A++] = nb[0][1]; ans[A++] = nb[0][2]; }
  else if(good(nb[0][3], nb[0][0], nb[0][2], nb[0][1])){ ans[A++] = nb[0][2]; ans[A++] = nb[0][1]; }
  else if(good(nb[0][0], nb[0][3], nb[0][2], nb[0][1])){ ans[A++] = nb[0][2]; ans[A++] = nb[0][1]; }
  else if(good(nb[0][0], nb[0][2], nb[0][1], nb[0][3])){ ans[A++] = nb[0][1]; ans[A++] = nb[0][3]; }
  else if(good(nb[0][2], nb[0][0], nb[0][1], nb[0][3])){ ans[A++] = nb[0][1]; ans[A++] = nb[0][3]; }
  else if(good(nb[0][2], nb[0][0], nb[0][3], nb[0][1])){ ans[A++] = nb[0][3]; ans[A++] = nb[0][1]; }
  else if(good(nb[0][0], nb[0][2], nb[0][3], nb[0][1])){ ans[A++] = nb[0][3]; ans[A++] = nb[0][1]; }
  else return false;
  REP(i, 3) used[ans[i]] = true;
  FOR(i, 3, N-1){
    bool ok = false;
    REP(j, 4){
      ans[i] = nb[ans[i-2]][j];
      if(!used[ans[i]] && edge(ans[i-2], ans[i]) && edge(ans[i-1], ans[i])){ ok = true; break; }
    }
    if(!ok) return false;
    used[ans[i]] = true;
  }
  return true;
}


int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, 2*N){ scanf("%d%d", a + i, b + i); a[i]--; b[i]--; }
  if(!solve()) printf("-1\n");
  else{
    REP(i, N){
      if(i) printf(" ");
      printf("%d", ans[i] + 1);
    }
    printf("\n");
  }
  return 0;
}