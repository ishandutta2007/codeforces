#include <iostream>
#include <cstdio>

#include <set>

using namespace std;

template<class T> void mx(T& a, const T& b) {if(a < b) a = b;}

const int MN = 1e5 + 100;
const int MM = 40 + 5;
const int ML = 50;

#define cti(X) (static_cast<int>(X) - 97)

template<int MS = MN*ML> struct TRIE {
public:
  int c[MN][26], v[MN];
  int X, R, C;
  int nn(int z = -1) {
    for(int i = 0;i < 26;i++) c[X][i] = 0;
    v[X] = z;
    return X++;
  }
  TRIE() : X(0), C(0) {nn(), R = nn();}
  int get(char * s) {
    int n = R;
    for(int i = 0;s[i] != '\0';i++) if(c[n][cti(s[i])]) n = c[n][cti(s[i])]; else n = c[n][cti(s[i])] = nn();
    if(v[n] != -1) return v[n];
    else return v[n] = C++;
  }
};
TRIE<> trie;

int N, M, C;
using si = set<int>;
si s;

using ll = long long;

ll T;
char I[ML];

ll z[MM];
ll a[1<<(MM>>1)];
int c[1<<(MM>>1)];
ll b[1<<(MM>>1)];

int f;

int l2[1<<(MM>>1)];

int main() {
  for(int i = 0, j = -1;i < (1<<(MM>>1));i++) {
    if(i>>(j+1)) j++;
    l2[i] = j;
  }
  
  scanf("%d%d", &N, &M);
  T = (1LL<<M)-1;
  
  for(int i = 0;i < M;i++) z[i] = T;
  
  for(int i = 0, o;i < N;i++) {
    scanf("%d", &o);
    if(o == 1) {
      if(not s.empty()) {
        ll v = 0LL;
        for(int x : s) v|=1LL<<x;
        v^=T;
        for(int x : s) z[x]&=v|1LL<<x;
        s.clear();
      }
    } else {
      scanf(" %s", I);
      s.insert(trie.get(I));
    }
  }
  if(not s.empty()) {
    ll v = 0LL;
    for(int x : s) v|=1LL<<x;
    v^=T;
    for(int x : s) z[x]&=v|1LL<<x;
    s.clear();
  }
  
  f = 0;
  C = M>>1;
  c[0] = 0;
  for(int i = 1;i < 1<<C;i++) {
    if(i == 1<<l2[i]) {
      a[i] = z[l2[i]]&((1<<C)-1), c[i] = 1;
      continue;
    }
    a[i] = a[i^1<<l2[i]]&z[l2[i]];
    if((a[i]&i) == i) c[i] = __builtin_popcount(i);
    else {
      c[i] = 0;
      for(int j = 0;j < C;j++) if(i&1<<j) mx(c[i], c[i^1<<j]);
    }
  }
  
  for(int i = 0;i < (1<<(M-C));i++) {
    if(i == 0) b[i] = T; else b[i] = b[i^1<<l2[i]]&z[l2[i]+C];
    if((b[i]>>C&i) == i) mx(f, __builtin_popcount(i) + c[b[i]&((1<<C)-1)]);
  }
  
  printf("%d\n", f);
  
  return 0;
}