#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<int>(X)
typedef long double ld;
#define tld(X) static_cast<ld>(X)

const int MN = 1e5 + 100;

int N;
char t[MN];
ll l[MN];

int main() {
  
  scanf("%d", &N);
  
  for(int i = 0;i < N;i++) scanf("%lld", l + i);
  for(int i = 0;i < N;i++) scanf(" %c", t + i);
  
  bool w = false;
  
  ll wf = 0LL, gf = 0LL;    //sacrifice wf before gf
  ll T = 0LL;
  for(int i = 0;i < N;i++) {
    ll d = l[i];
    if(t[i] == 'G') {
      if(wf > d) {
        T += d * 2;
        wf -= d;
        gf += d << 1LL;
      } else {
        d -= wf;
        T += wf * 2;
        gf += wf<<1;
        wf = 0;
        
        T += d * (5 + 1)>>1;
        gf += d;
      }
    }
    if(t[i] == 'W') {
      w = true;
      
      T += d * (1 + 3)>>1;
      wf += d;
    }
    if(t[i] == 'L') {
      if(wf >= d) {
        T += d * 2;
        wf -= d;
        continue;
      }
      d -= wf;
      T += wf * 2;
      wf = 0;
      
      if(gf >= d) {
        T += d * 3;
        gf -= d;
        continue;
      }
      d -= gf;
      T += gf * 3;
      gf = 0;
      
      if(w) T += 4LL * d;
      else T += 6LL * d;
    }
  }
  
  printf("%lld\n", T);
  
  return 0;
}