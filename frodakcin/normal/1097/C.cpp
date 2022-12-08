#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5 + 100;
const int ML = 5e5 + 100;

char s[ML];

int N;

template <class T> void rpl(T& a, const T& b) {if(b < a) a = b;}

int L[ML], R[ML];
bool m;

int f;

void add(char * s) {
  int p = 0, S;
  for(S = 0;s[S] != '\0';S++);
  
  for(int i = 0;;i++) {
    if(i == S) {
      if(p == 0) {
        f += m;
        m = not m;
        return;
      }
      if(R[p]) f++, R[p]--;
      else L[p]++;
      break;
    }
    if(s[i] == '(') p++;
    else p--;
    if(p < 0) break;
  }
  
  p = 0;
  bool r = true;
  for(int i = S - 1;i >= 0;i--) {
    if(s[i] == ')') p++;
    else p--;
    if(p < 0) {r = false; break;}
  }
  if(r) {
    if(L[p]) f++, L[p]--;
    else R[p]++;
  }
}

int main() {
  scanf("%d", &N);
  
  for(int i = 0;i < ML;i++) L[i] = R[i] = 0;
  m = false;
  f = 0;
  
  for(int i = 0;i < N;i++) {
    scanf(" %s", s);
    add(s);
  }
  
  printf("%d\n", f);
  
  return 0;
}