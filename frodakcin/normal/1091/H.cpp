#include <iostream>
#include <cstdio>

#include <bitset>
#include <cassert>

using namespace std;

const int MN = 2e5 + 100;
const int MV = 2e5 + 100;
const int MM = 100;
const int MP = 2e4 + 100; //~17800

int N, F;
int g[MV];

using bs = bitset<MV>;

bs G[MM];
bs p, s;
int L[MP];

void pcpp() {
  p.set(); s.reset();
  L[0] = 0;
  for(int i = 2;i < MV;i++) {
    if(p[i]) {
      L[++L[0]] = i;
      s[i] = true;
    }
    for(int j = 1, k;j <= L[0] and (k = L[j] * i) < MV;j++) {
      if(p[i]) s[k] = true;
      p[k] = false;
      if(i%L[j] == 0) break;
    }
  }
  s[F] = false;
}

void pcpg() {
  pcpp();
  
  for(int i = 0;i < MM;i++) G[i].reset();
  
  g[0] = -1;
  g[1] = g[2] = 0;
  G[0] |= s<<1, G[0] |= s<<2;
  
  for(int i = 3;i < MV;i++) {
    for(g[i] = 0;;g[i]++) {
      assert(g[i] < MM);
      if(not G[g[i]][i]) break;
    }
    G[g[i]] |= (s<<i);
  }
}

int main() {
  scanf("%d%d", &N, &F);
  
  pcpg();
  
  int f = 0;
  for(int i = 0, a[3];i < N;i++) {
    scanf("%d%d%d", a, a + 1, a + 2);
    f ^= g[a[1] - a[0]] xor g[a[2] - a[1]];
  }
  
  if(f) printf("Alice\nBob\n");
  else printf("Bob\nAlice\n");
  
  return 0;
}