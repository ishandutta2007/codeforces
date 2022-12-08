#include <iostream>
#include <cstdio>

#include <array>
#include <vector>

using namespace std;

const int MN = 5e5 + 100;
const int INF = 1e7;

char s[MN], t[MN];
int N;
using c2 = array<char, 2>;
c2 S[MN];
bool operator ^ (const c2& a, const c2& b) {return a[0] == b[1] and b[0] == a[1];}

using i3 = array<int, 3>;
using vi3 = vector<i3>;
#define pb push_back
using i2 = array<int, 2>;

i2 rp(i2& a, i2 b) {
  if(b[0] != -1 and (a[0] == -1 or b[0] < a[0])) a = b;
  return a;
}

int y;
i2 d[MN], g[MN];
vi3 v[2];
void ins(int a, int b, int c) {
  y = b;
  if(not v[0].empty() and c == v[0].back()[2]) v[0].back()[1] = b;
  else v[0].pb({a, b, c});
}
void ins(int a) {ins(a, a, a-y);}
int solve() {
  for(vi3& x : v) x.clear();
  for(int i = 0;i <= N;i++) d[i] = {-1, -2}, g[i] = {-1, -1};
  d[0] = {0, -1};
  for(int i = 0;i < N;i++) {
    v[0].clear();
    y = -INF;
    for(i3 x : v[1]) if(x[0] >= 0 and S[x[0]]^S[i]) {
      x[0]--, x[1]--;
      ins(x[0]);
      if(x[0] != x[1]) ins(x[0] + x[2], x[1], x[2]);
    }
    if(i and S[i] ^ S[i-1]) ins(i - 2);
    if(S[i] ^ S[i]) ins(i - 1), d[i+1] = {d[i][0], i};
    
    for(i3 x : v[0]) {
      i2 z = d[x[1] + 1][0] == -1 ? i2{-1, -1} : i2{d[x[1] + 1][0] + 1, x[1] + 1};
      if(x[0] < x[1]) rp(z, g[x[0]+1-x[2]]);
      if(x[0]+1 >= x[2]) g[x[0]+1-x[2]] = z;
      rp(d[i+1], z);
    }
    
    v[0].swap(v[1]);
  }
  
  if(d[N][0] == -1) return printf("-1\n"), 0;
  printf("%d\n", d[N][0]);
  for(int i = N;i > 0;i = d[i][1]) if(i - d[i][1] > 1) printf("%d %d\n", d[i][1] + 1, i);
  
  return 0;
}

int main() {
  scanf(" %s %s", s, t);
  
  for(N = 0;s[N] != '\0';N++) S[N] = {s[N], t[N]};
  
  solve();
  
  return 0;
}