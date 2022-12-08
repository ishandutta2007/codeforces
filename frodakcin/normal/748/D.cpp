#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <functional>
#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXK = 1e5 + 100;
const int MAXP = 1e5 + 100;

int N, K;

char tmp[MAXK];
string s[MAXN];
int a[MAXN];

int ans, mc;

typedef vector<int> vi;
#define pb push_back

#define ti(x) static_cast<int>(x)
inline int ci(const char& c) {return ti(c) - 97;}

const int MAXS = MAXP << 4;
struct TRIE {
  int c[MAXP][26];
  bitset<MAXP> u;
  vi v[MAXP];
  int X, H;
  int nn() {
    for(int i = 0;i < 26;i++) c[X][i] = 0;
    u[X] = false;
    v[X] = vi();
    return X++;
  }
  TRIE() : X(1) {H = nn();}
  
  void ins(const string& s, int w) {
    int q = H;
    for(int i = 0;i < s.size();i++) 
      if(c[q][ci(s[i])]) q = c[q][ci(s[i])]; else q = c[q][ci(s[i])] = nn();
    v[q].pb(w);
  }
  void fix() {
    for(int i = 1;i < X;i++) if(not v[i].empty()) sort(v[i].begin(), v[i].end(), greater<int>());
  }
  int get(const string& s) {
    int q = H;
    for(int i = 0;i < s.size();i++) {
      q = c[q][ci(s[i])];
      if(q == 0) return 0;
    }
    return q;
  }
  int getrv(const string& s) {
    int q = H;
    for(int i = s.size() - 1;i >= 0;i--) {
      q = c[q][ci(s[i])];
      if(q == 0) return 0;
    }
    return q;
  }
} trie;

void rph(int& a, const int& b) {if(a < b) a = b;}

int main() {
  scanf("%d%d", &N, &K);
  
  for(int i = 0;i < N;i++) {
    scanf(" %s%d", tmp, a + i);
    s[i] = tmp;
  }
  
  ans = mc = 0;
  for(int i = 0;i < N;i++) trie.ins(s[i], a[i]);
  trie.fix();
  
  for(int i = 0;i < N;i++) {
    int v = trie.get(s[i]);
    assert(v);
    if(trie.u[v]) continue;
    trie.u[v] = true;
    int w = trie.getrv(s[i]);
    if(not w) continue;
    
    if(v == w) {
      int t = 0;
      for(;t + 1 < trie.v[v].size();t += 2)
        if(trie.v[v][t] + trie.v[v][t + 1] > 0) ans += trie.v[v][t] + trie.v[v][t + 1]; else break;
      if(t < trie.v[v].size()) rph(mc, trie.v[v][t]);
      if(t and trie.v[v][t - 1] < 0) rph(mc, -trie.v[v][t - 1]);
    } else {
      trie.u[w] = true;
      for(int i = 0;i < trie.v[v].size() and i < trie.v[w].size();i++)
        if(trie.v[v][i] + trie.v[w][i] > 0) ans += trie.v[v][i] + trie.v[w][i]; else break;
    }
    //cerr << s[i] << " " << ans << " " << mc << "\n";
  }
  
  printf("%d\n", ans + mc);
  
  return 0;
}