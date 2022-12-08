#include <iostream>
#include <cstdio>

#include <bitset>

using namespace std;

template<int T> using bs = bitset<T>;

const int MQ = 1e6 + 100;
const int MV = 7000 + 100;
const int MVR = 100;
const int MN = 1e5 + 100;

bs<MV> m[MN], u[MN];
bs<MV> s[MN];

void pcpm() {
  for(int i = 1;i < MV;i++) m[i].reset();
  for(int i = 1;i < MV;i++)
    for(int j = i;j < MV;j+=i) m[j][i] = true;
  
  int l[MV], v[MV];
  for(int i = 0;i < MV;i++) {
    l[i] = -1;
  }
  v[1] = 1;
  for(int i = 2;i < MV;i++) {
    if(l[i] == -1) l[i] = i, v[i] = 1;
    for(int j = 2, k;(k=i*j)<MV;j++) {
      if(l[k] == -1 or l[k] > l[i]) l[k] = l[i];
      if(l[k] == l[i]) v[k] = 0;
      if(l[k] < l[i]) v[k] = -v[i];
    }
  }
  
  for(int i = 0;i < MV;i++) u[i].reset();
  for(int i = 1;i < MV;i++)
    for(int j = 1, k;(k=i*j) < MV;j++)
      if(v[j]) u[i][k] = true;
}

int N, Q;

int main() {
  pcpm();
  
  scanf("%d%d", &N, &Q);
  
  for(int i = 1;i <= N;i++) s[i].reset();
  
  for(int i = 0, q[4];i < Q;i++) {
    scanf("%d", q);
    if(q[0] == 1) scanf("%d%d", q+1, q+2), s[q[1]]=m[q[2]];
    if(q[0] == 2) scanf("%d%d%d", q+1, q+2, q+3), s[q[1]]=s[q[2]]^s[q[3]];
    if(q[0] == 3) scanf("%d%d%d", q+1, q+2, q+3), s[q[1]]=s[q[2]]&s[q[3]];
    if(q[0] == 4) scanf("%d%d", q+1, q+2), printf("%lu", (s[q[1]]&u[q[2]]).count()&1);
  }
  
  printf("\n");
  
  return 0;
}