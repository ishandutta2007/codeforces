#include <iostream>
#include <cstdio>

#include <bitset>

using namespace std;

const int MAXN = 5e5 + 100;

int N, K;

typedef bitset<MAXN> vb;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

vb s, t, F;
char p[MAXN];
ll c;
ll ans;

int main() {
  scanf("%d%d", &N, &K);
  
  s.reset();t.reset();F.reset();
  
  scanf(" %s", p);
  for(int i = 0;i < N;i++) s[i] = p[i] == 'b';
  scanf(" %s", p);
  for(int i = 0;i < N;i++) t[i] = p[i] == 'b';
  F = s xor t;
  
  int f = 1;
  c = 0LL;
  ans = 0LL;
  for(int i = 0;i < N;i++) {
    c <<= 1LL;
    if(F[i] and f == 1) f = 2;
    else if(f == 2) {
      if(not s[i]) c++;
      if(t[i]) c++;
    }
    
    if(not(c + tll(f) < tll(K))) {ans += tll(N-i)*tll(K); break;}
    
    ans += c + tll(f);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}