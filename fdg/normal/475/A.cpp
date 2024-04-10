#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[6][55] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+",};

int main() {
  int n;
  cin >> n;
  for (int i = 0; n > 0 && i < 55; ++i) {
    for (int j = 0; n > 0 && j < 6; ++j)
      if (f[j][i] == '#') {
        f[j][i] = 'O';
        --n;
      }
  }
  for (int i = 0; i < 6; ++i)
    puts(f[i]);
  return 0;
}