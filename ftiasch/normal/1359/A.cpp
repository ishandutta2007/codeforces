#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int cards, jokers, players;
    scanf("%d%d%d", &cards, &jokers, &players);
    int size = cards / players;
    int max = std::min(jokers, size);
    printf("%d\n", max - ((jokers - max) + (players - 2)) / (players - 1));
  }
}