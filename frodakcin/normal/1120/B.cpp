#include <iostream>
#include <cstdio>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
const int MN = 1e5 + 100;
const int MC = 1e5; 

int a[MN], b[MN], p[MN], N;
ll d[MN];
ll C;
int S;

void brute(int x) {
  if(x < 0||x >= N-1) return;
  if(!d[x]) return;
  bool w = 1;
  if(0 < d[x])
    if(a[x]!=9&&a[x+1]!=9)
      printf("%d 1\n", x+1), a[x]++, a[x+1]++, d[x]--;
    else
      w = 0;
  else
    if(a[x]&&a[x+1]&&(x||a[x]>1))
      printf("%d -1\n", x+1), a[x]--, a[x+1]--, d[x]++;
    else
      w = 0;
  if(!w) return;
  if(++S == C) exit(0);
  brute(x);
  brute(x-1);
  brute(x+1);
}

int main() {
  scanf("%d", &N);
  for(int i = 0;i < N;i++) {
    char c;
    scanf(" %c", &c);
    a[i] = c - '0';
  }
  for(int i = 0;i < N;i++) {
    char c;
    scanf(" %c", &c);
    b[i] = c - '0';
  }
  for(int i = 0, j;i < N;i++) {
    p[i] += a[i];
    d[i] = b[i] - p[i];
    C += abs(b[i] - p[i]);
    p[i+1] += b[i] - p[i];
  }
  if(p[N] != 0)
    return printf("-1\n"), 0;
  printf("%lld\n", C);
  if(C > MC) C = tl(MC);
  else if(C == 0LL) return 0;
  S = 0;
  for(int i = 0;i < N-1&&S < C;i++)
    brute(i);
  return 0;
}