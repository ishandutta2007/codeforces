#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 5e5 + 100;

int N;

void rph(int& a, const int& b) {if(a < b) a = b;}

typedef vector<int> vi;
#define pb push_back

typedef long long ll;

vi h[MAXN];
void ctsort(int * a, const int& s, int * c) {
  int M = 0;
  for(int i = 0;i < s;i++) h[c[a[i]]].pb(a[i]), rph(M, c[a[i]]);
  for(int i = 0, q = 0;i <= M;i++) {
    for(int u : h[i]) a[q++] = u;
    h[i].clear();
  }
}

char s[MAXN];
int sa[MAXN], isa[MAXN];
int r[2][MAXN], t[MAXN];
bool sm(int a, int b) {
  for(int i = 0;i < 2;i++) if(r[i][a] != r[i][b]) return false;
  return true;
}
void gsa() {
  for(int i = 0;i < N;i++) sa[i] = i;
  for(int i = 0;i < N;i++) r[0][i] = static_cast<int>(s[i]), r[1][i] = 0;
  for(int i = 1;i >= 0;i--) ctsort(sa, N, r[i]);
  for(int l = 1, c;l < N;l<<=1) {
    t[sa[0]] = c = 1;
    for(int i = 1;i < N;i++) if(sm(sa[i-1], sa[i])) t[sa[i]] = c; else t[sa[i]] = ++c;
    for(int i = 0;i < N;i++) {
      r[0][i] = t[i];
      if(i + l < N) r[1][i] = t[i + l]; else r[1][i] = 0;
    }
    for(int i = 1;i >= 0;i--) ctsort(sa, N, r[i]);
  }
  for(int i = 0;i < N;i++) isa[sa[i]] = i;
}
int lcp[MAXN];
void glcp() {
  for(int i = 0, p = 0;i < N;i++) {
    if(isa[i] + 1 == N) {
      lcp[isa[i]] = 0;
      p = 0;
      continue;
    }
    while(i + p < N and sa[isa[i] + 1] + p < N and s[i + p] == s[sa[isa[i] + 1] + p]) p++;
    lcp[isa[i]] = p;
    if(p > 0) p--;
  }
}

const int NL2 = 20;
int n[NL2][MAXN], w[MAXN];
int L[MAXN];

int jump(int s, int a) {
  if(s == a) return s;
  assert(s < a);
  for(int i = L[a - s];i >= 0;i--)
    if(n[i][s] != -1 and n[i][s] <= a) s = n[i][s];
  return s;
}

int main() {
  for(int i = 0, j = 0;i < MAXN;i++) {
    if(i&(1<<j)) j++;
    L[i] = j;
  }
  
  scanf("%d", &N);
  scanf(" %s", s);
  
  gsa();
  glcp();
  
  //for(int i = 0;i < N;i++) cerr << sa[i] << " " << lcp[i] << " " << (s + sa[i]) << "\n";
  
  for(int i = 0;i <= N;i++) 
    for(int j = 0;j < NL2;j++) n[j][i] = -1;
  for(int i = 0, c = 0;i < N;i++) {
    if(s[i] == '(') t[c++] = i;
    else if(c > 0) n[0][t[--c]] = i + 1;
  }
  
  for(int i = N - 1;i >= 0;i--) for(int j = 0;;j++) if(n[j][i] != -1 and n[j][n[j][i]] != -1) n[j+1][i] = n[j][n[j][i]]; else break;
  for(int i = 0;i <= N;i++) w[i] = 0;
  for(int i = N;i >= 0;i--)
    if(n[0][i] != -1) w[i] = w[n[0][i]] + 1;
  
  //for(int i = 0;i < N;i++) cerr << w[i] << "\n";
  
  ll f = 0;
  for(int i = 0;i < N - 1;i++) {
    int j = jump(sa[i], sa[i] + lcp[i]);
    if(-1 < j and j < N) f += w[j];
  }
  
  printf("%lld\n", f);
  
  return 0;
}