#include <iostream>
#include <cstdio>

using namespace std;

const int MAXB = 30;
const int MAXV = (1 << MAXB) - 1;

int cb;

int gR(int a, int b) {
  int r;
  printf("? %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &r);
  if(r == -2) exit(0);
  return r;
}

void fin(int a, int b) {
  for(;cb >= 0;cb--)
    if(gR(a ^ (1 << cb), b) == -1) a |= 1 << cb, b |= 1 << cb;
  printf("! %d %d\n", a, b);
  exit(0);
}

int g(int a, int b) {
  int r = gR(a, b);
  if(r == 0) fin(a, b);
  return r;
}

int a, b, r[3];

int main() {
  a = b = r[2] = 0;
  for(cb = MAXB - 1;cb >= 0;cb--) {
    if(r[2] == 0) {
      r[0] = g(a, b);
      r[1] = g(a xor (1 << cb), b xor (1 << cb));
      r[2] = (r[0] + r[1])>>1;
      if(r[0] == 1 and r[1] == -1) a |= 1 << cb;
      else if (r[0] == -1 and r[1] == 1) b |= 1 << cb;
      else
        if(g(a xor (1 << cb), b) == -1) a |= 1 << cb, b |= 1 << cb;
    } else {
      if(g(a xor (1<<cb), b xor (1<<cb)) == r[2]) {
        if(g(a xor (1 << cb), b) == -1) a |= 1 << cb, b |= 1 << cb;
      } else {
        if(r[2] == 1) a |= 1 << cb;
        else b |= 1 << cb;
        r[2] = 0;
      }
    }
  }
  printf("! %d %d\n", a, b);
  
  return 0;
}