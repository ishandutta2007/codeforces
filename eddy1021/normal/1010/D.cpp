#include <bits/stdc++.h>
using namespace std;
#define IN 0
#define AND 1
#define OR 2
#define XOR 3
#define NOT 4
const int N=(1<<20);
int n, tp[N], lc[N], rc[N], val[N], e[N];
inline int f(int type, int x, int y){
  if(type==AND) return x&y;
  if(type==OR) return x|y;
  if(type==XOR) return x^y;
  assert(false);
  return -1;
}
int go(int nd){
  if(tp[nd] == IN) return val[nd];
  if(tp[nd] == NOT) return val[nd]=1-go(lc[nd]);
  return val[nd]=f(tp[nd], go(lc[nd]), go(rc[nd]));
}
void go2(int nd){
  e[nd]=1;
  if(tp[nd] == IN) return;
  if(tp[nd] == NOT){
    go2(lc[nd]);
    return;
  }
  if(val[nd] != f(tp[nd], 1-val[lc[nd]], val[rc[nd]]))
    go2(lc[nd]);
  if(val[nd] != f(tp[nd], val[lc[nd]], 1-val[rc[nd]]))
    go2(rc[nd]);
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    char buf[9]; scanf("%s", buf);
    if(buf[0]=='I'){
      tp[i]=IN;
      scanf("%d", &val[i]);
      continue;
    }
    if(buf[0]=='N'){
      tp[i]=NOT;
      scanf("%d", &lc[i]);
      continue;
    }
    if(buf[0]=='A') tp[i]=AND;
    if(buf[0]=='O') tp[i]=OR;
    if(buf[0]=='X') tp[i]=XOR;
    scanf("%d%d", &lc[i], &rc[i]);
  }
  go(1);
  go2(1);
  for(int i=1; i<=n; i++)
    if(tp[i]==IN)
      printf("%d", e[i]^val[1]);
  puts("");
}