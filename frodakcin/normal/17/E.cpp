#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 51123987;

const int MN = 2e6 + 1000;

int N;
char s[MN];

using ll = long long;
ll T, F;

int e[MN], o[MN];
void manacher() {
  for(int i = 0, m = -1, l = -1;i < N - 1;i++) {
    if(m + l > i) e[i] = min(e[(m<<1) - i], m + l - i); else e[i] = 0;
    while(i >= e[i] and i + e[i] + 1 < N and s[i-e[i]] == s[i + e[i] + 1]) e[i]++;
    if(i + e[i] > m + l) m = i, l = e[i];
  }
  e[N-1] = 0;
  
  for(int i = 0, m = -1, l = -1;i < N;i++) {
    if(m + l > i) o[i] = min(o[(m<<1) - i], m + l - i); else o[i] = 1;
    while(i >= o[i] and i + o[i] < N and s[i-o[i]] == s[i+o[i]]) o[i]++;
    if(i + o[i] > m + l) m = i, l = o[i];
  }
  T = 0LL;
  for(int i = 0;i < N;i++) T += e[i] + o[i];
  T %= MOD;
}

ll c2(ll x) {
  if(x&1) return x*(x>>1);
  else return (x>>1)*(x-1);
}
int p[MN], q[MN];
ll A, L, R;
void solve() {
  F = 0LL;
  
  for(int i = 0;i <= N;i++) p[i] = q[i] = 0;
  for(int i = 0;i < N;i++) {
    p[i-e[i]+1]++;
    p[i-o[i]+1]++;
    p[i+1]-=2;
  }
  for(int i = 0;i < N;i++) {
    q[i]++;
    q[i+1]++;
    q[i+e[i]+1]--;
    q[i+o[i]]--;
  }
  
  A = L = R = 0LL;
  for(int i = 0;i < N;i++) {
    L += (A += p[i]) - (R += q[i]);
    F += L%MOD*R%MOD + c2(R%MOD)%MOD;
  }
  
  printf("%lld\n", (F+MOD)%MOD);
}

int main() {
  scanf(" %d%s", &N, s);
  
  manacher();
  solve();
  
  return 0;
}