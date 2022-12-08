#include <iostream>
#include <cstdio>

#include <utility>

using namespace std;

const int MAXS = 1e5 + 100;
const int MAXT = 1e6 + 100;

void zfunc(int * s, int * z, const int& L) {
  z[0] = L;
  for(int i = 1, l = -1, r = -1;i < L;i++) {
    if(i < r) z[i] = min(z[i - l], r - i); else z[i] = 0;
    while(i + z[i] < L and s[z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] > r) r = i + z[i], l = i;
  }
}

int S, T;
char inp[MAXT];
bool s[MAXS];
int t[MAXT];
int c[2];

int z[MAXT];

typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair

const int MOD0 = 1e9 + 7;
const int MOD1 = 1e9 + 9;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

pii operator * (const pii& a, const pii& b) {
  return mp(ti((tll(a.ff) * tll(b.ff))%MOD0), ti((tll(a.ss) * tll(b.ss))%MOD1));
}
pii operator * (const pii& a, const int& b) {
  return a * mp(b, b);
}
pii operator + (const pii& a, const pii& b) {
  return mp(ti((tll(a.ff) + tll(b.ff))%MOD0), ti((tll(a.ss) + tll(b.ss))%MOD1));
}
pii operator - (const pii& a, const pii& b) {
  return mp(ti((tll(a.ff) - tll(b.ff) + 100LL * MOD0)%MOD0), ti((tll(a.ss) - tll(b.ss) + 100LL * MOD1)%MOD1));
}
int prod(int a, int b, int M) {
  return ti((tll(a) * tll(b))%M);
}
int pow(int b, int p, int M) {
  int r = 1;
  for(;p;p>>=1, b=prod(b, b, M)) if(p&1) r=prod(r, b, M);
  return r;
}
pii operator / (const pii& a, const pii& b) {
  return a * mp(pow(b.ff, MOD0 - 2, MOD0), pow(b.ss, MOD1 - 2, MOD1));
}
bool operator == (const pii& a, const pii& b) {
  return a.ff == b.ff and a.ss == b.ss;
}

pii hsh[MAXT];
pii dv[MAXT];
void do_hash() {
  hsh[0] = mp(0, 0);
  dv[0] = mp(1, 1);
  dv[1] = dv[0]/mp(26, 26);
  pii b(1, 1);
  for(int i = 0;i < T;i++) {
    hsh[i + 1] = hsh[i] + (mp(t[i], t[i])*b);
    b = b*26;
    if(i > 0) dv[i + 1] = dv[i]*dv[1];
  }
}

pii get_hash(int l, int r) {    //left inclusive, right exclusive
  return (hsh[r] - hsh[l])*dv[l];
}

pii fin;
int a1;
bool test(int l0, int l1) {
  fin = get_hash(l0 * a1, l0 * a1 + l1);
  if(l0 == l1 and fin == get_hash(0, l0)) return false;
  for(int i = 1, l = l0;i < S;i++) {
    if(!s[i]) {
      if(z[l] < l0) return false;
      l += l0;
    } else {
      if(fin != get_hash(l, l + l1)) return false;
      l += l1;
    }
  }
  return true;
}

int main() {
  scanf(" %s", inp);
  for(S = 0;inp[S] != '\0';S++) s[S] = (static_cast<int>(inp[S])-48);
  scanf(" %s", inp);
  for(T = 0;inp[T] != '\0';T++) t[T] = static_cast<int>(inp[T]) - 97;
  
  if(s[0]) for(int i = 0;i < S;i++) s[i] = !s[i];
  
  zfunc(t, z, T);
  do_hash();
  
  int ans = 0;
  
  c[0] = c[1] = 0;
  for(int i = 0;i < S;i++) c[s[i]]++;
  for(a1 = 1;s[a1] == 0;a1++);
  
  for(int v0 = 1, v1;v0*c[0] < T;v0++) {
    if(((T - v0*c[0])%c[1] == 0) and test(v0, (T - v0*c[0])/c[1])) ans++;
  }
  
  printf("%d\n", ans);
  
  return 0;
}