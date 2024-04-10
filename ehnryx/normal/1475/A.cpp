#include <stdio.h>
#include <bits/stdc++.h>
long long read_integer() {
  long long long_long;
  std::cin >> long_long;
  return long_long;
}
int main() {
  int t, n, sad, eyqs, cactus;
  std::cin >> t;
  while(t--) {
    long long long_eyqs;
    std::cout << (__builtin_popcountll(read_integer()) == 1 ? "NO" : "YES") << '\n';
  }}