#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int LL, LR, RL, RR;
  scanf("%d%d%d%d", &LL, &LR, &RL, &RR);
  puts(LL == RR && (!RL || LL) ? "1" : "0");
}