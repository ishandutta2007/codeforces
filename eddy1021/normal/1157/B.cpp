#include <bits/stdc++.h>
using namespace std;
const int N=202020;
char c[N];
int n, f[10];
int main(){
  scanf("%d%s", &n, c);
  for (int i=1; i<10; ++i) {
    scanf("%d", &f[i]);
  }
  int ptr=0;
  while (ptr<n) {
    if (f[c[ptr] - '0'] > c[ptr] - '0')
      break;
    ++ptr;
  }
  for (; ptr < n; ++ptr) {
    if (f[c[ptr] - '0'] < c[ptr] - '0')
      break;
    c[ptr] = f[c[ptr] - '0'] + '0';
  }
  puts(c);
}