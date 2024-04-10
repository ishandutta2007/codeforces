#include <iostream>
#include <cstdio>

using namespace std;

const int MAXL = 3e6 + 100;

int N, K;

char S[MAXL], A[MAXL], B[MAXL];
int s[MAXL], a[MAXL], b[MAXL];

#define cti(X) (static_cast<int>(X) - 97)
#define itc(X) static_cast<char>(X + 97)

const int MAXK = 30;

int f[MAXK];
bool u[MAXK];

void fail() {
  printf("NO\n");
}
bool ans() {
  printf("YES\n");
  for(int i = 0, j = -1;i < K;i++) {
    if(f[i] == -1) {
      for(j++;u[j];j++);
      printf("%c", itc(j));
    } else printf("%c", itc(f[i]));
  }
  printf("\n");
  return true;
}

bool tb() {
  for(int i = 0;i < K;i++) f[i] = -1, u[i] = false;
  bool I = true;
  for(int i = 0;i < N;i++) {
    int& c = f[s[i]];
    if(I and a[i] != b[i]) {
      I = false;
      if(c == -1) {
        for(int j = a[i] + 1;j < b[i];j++)
          if(not u[j]) {c = j, u[j] = true; return ans();}
        if(u[b[i]]) return false;
        u[b[i]] = true, c = b[i];
      } else {
        if(c <= a[i] or c > b[i]) return false;
        if(c < b[i]) return ans();
      }
    } else if(I) {
      if(c == -1) {
        if(u[b[i]]) return false;
        c = b[i], u[b[i]] = true;
      } else
        if(c != b[i]) return false;
    } else {
      if(c == -1) {
        for(int j = 0;j < b[i];j++) 
          if(not u[j]) {c = j, u[j] = true; return ans();}
        if(u[b[i]]) return false;
        u[b[i]] = true, c = b[i];
      } else {
        if(c < b[i]) return ans();
        if(c > b[i]) return false;
      }
    }
  }
  return ans();
}
bool ta() {
  for(int i = 0;i < K;i++) f[i] = -1, u[i] = false;
  bool I = true;
  for(int i = 0;i < N;i++) {
    int& c = f[s[i]];
    if(I and a[i] != b[i]) {
      I = false;
      if(c == -1) {
        for(int j = a[i] + 1;j < b[i];j++)
          if(not u[j]) {c = j, u[j] = true; return ans();}
        if(u[a[i]]) return false;
        u[a[i]] = true, c = a[i];
      } else {
        if(c < a[i] or c >= b[i]) return false;
        if(c > a[i]) return ans();
      }
    } else if(I) {
      if(c == -1) {
        if(u[a[i]]) return false;
        c = a[i], u[a[i]] = true;
      } else
        if(c != a[i]) return false;
    } else {
      if(c == -1) {
        for(int j = a[i] + 1;j < K;j++) 
          if(not u[j]) {c = j, u[j] = true; return ans();}
        if(u[a[i]]) return false;
        u[a[i]] = true, c = a[i];
      } else {
        if(c > a[i]) return ans();
        if(c < a[i]) return false;
      }
    }
  }
  return ans();
}

void solve() {
  scanf("%d", &K);
  scanf(" %s %s %s", S, A, B);
  for(N = 0;S[N] != '\0';N++) s[N] = cti(S[N]), a[N] = cti(A[N]), b[N] = cti(B[N]);
  
  if(tb()) return;
  if(ta()) return;
  return fail();
}

int T;

int main() {
  scanf("%d", &T);
  while(T--) solve();
  
  return 0;
}