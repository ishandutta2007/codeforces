#include <iostream>
#include <cstdio>

#include <bitset>
#include <algorithm>
#include <functional>

#include <ctime>
#include <iomanip>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXV = 1e6 + 100;

typedef bitset<MAXV + 10> vb;

vb sieve;
int p[80000], ps;
int s[MAXV], v[MAXV], n[MAXV];

int N, dp[MAXN];
bool dpc;

const int MOD = 1e9 + 7;
typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}

int f[30], c[30], r;
void fact(int a, int& i) {
  if(a == 1) return;
  f[i] = s[a], c[i] = v[a];
  ++i;
  fact(n[a], i);
}
int z[300], zs;
void work(int i = 0, int a = 1) {
  if(i == r) {
    if(a <= N) z[zs++] = a;
    return;
  }
  for(int j = 0;j <= c[i];j++, a*=f[i]) work(i + 1, a);
}
void solve(const int& a) {
  fact(a, r = 0);
  zs = 0;
  work();
  sort(z, z + zs, greater<int>());
  for(int i = 0;i < zs;i++) dp[z[i]] = sum(dp[z[i]], dp[z[i]-1]);
}

int main() {
  clock_t timer = clock();cerr << setprecision(3);
  
  ps = 0;
  for(int i = 0;i < MAXV;i++) sieve[i] = true;
  
  for(int i = 2;i < MAXV;i++) {
    if(sieve[i]) p[ps++] = i, s[i] = i, v[i] = 1, n[i] = 1;
    for(int j = 0, k;j < ps and (k = i*p[j]) < MAXV;j++) {
      sieve[k] = false;
      s[k] = p[j];
      if(s[i] == s[k]) v[k] = v[i] + 1, n[k] = n[i]; else v[k] = 1, n[k] = i;
      if(i%p[j] == 0) break;
    }
  }
  
  scanf("%d", &N);
  dpc = false;
  for(int i = 1;i <= N;i++) dp[i] = 0;
  dp[0] = 1;
  for(int i = 0, a;i < N;i++) {
    scanf("%d", &a);
    solve(a);
  }
  
  int ans = 0;
  for(int i = 1;i <= N;i++) ans = sum(ans, dp[i]);
  printf("%d\n", ans);
  
  cerr << "Time: " << static_cast<double>(clock()-timer)/CLOCKS_PER_SEC << "s\n";
  
  return 0;
}