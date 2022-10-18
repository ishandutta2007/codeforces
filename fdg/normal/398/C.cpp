#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 5) {
    puts("1 4 1\n2 3 2\n 3 4 2\n2 5 1\n1 2\n 4 5\n");
  } else {
    for (int i = 0; i < n / 2; ++i)
      cout << i + 1 << " " << i + n / 2 + 1 << " " << 1 << endl;
    for (int i = n / 2; i + 1 < n; ++i)
      cout <<  i + 1 << " " << i + 2 << " " << 2 * (i - n / 2) + 1 << endl;
    cout << "1 3" << endl;
    for (int i = 0; i + 1 < n / 2; ++i)
      cout << i + 1 << " " << i + 2 << endl;
  }
  return 0;
}