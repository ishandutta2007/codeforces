#include <iostream>
#include <cstdio>

#include <set>

using namespace std;

const int MV = 1e9 + 1000;
const int MN = 5e5 + 1000;
const int VL2 = 40;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int l2(int v) {
  int r = 0;
  for(;v>>=1;) r++;
  return r;
}

using si = multiset<int>;
si v[VL2];
ll c[VL2];

int Q;

char I;
int x;
int f, t;

void recalc() {
  ll r = 0;
  f = 0;
  for(int i = 0;i < VL2;r += c[i++])
    if(not v[i].empty()) f += r < (1<<i) and r*2 < *v[i].begin();
}

int main() {
  scanf("%d", &Q);
  
  f = t = 0;
  for(int i = 0;i < Q;i++) {
    scanf(" %c%d", &I, &x);
    int s = l2(x);
    if(I == '+') {
      t++;
      c[s] += x;
      v[s].insert(x);
      recalc();
    } else {
      t--;
      c[s] -= x;
      v[s].erase(v[s].find(x));
      recalc();
    }
    printf("%d\n", t - f);
  }
  
  return 0;
}