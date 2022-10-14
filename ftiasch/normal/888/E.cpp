#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 35;
const int N2 = 18;

int n, n2, mod, a[N];
std::vector<int> residues;

void gen(int i, int s) {
  if (i == n2) {
    residues.push_back(s);
  } else {
    gen(i + 1, s);
    gen(i + 1, (s + a[i]) % mod);
  }
}

int result = 0;

void gen2(int i, int s) {
  if (i == n) {
    auto it = std::lower_bound(residues.begin(), residues.end(), mod - s);
    if (it != residues.begin()) {
      result = std::max(result, *std::prev(it) + s);
    }
    if (it != residues.end()) {
      result = std::max(result, residues.back() + s - mod);
    }
  } else {
    gen2(i + 1, s);
    gen2(i + 1, (s + a[i]) % mod);
  }
}

int main() {
  scanf("%d%d", &n, &mod);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  n2 = n >> 1;
  residues.reserve(1 << n2);
  gen(0, 0);
  std::sort(residues.begin(), residues.end());
  gen2(n2, 0);
  printf("%d\n", result);
}