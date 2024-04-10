#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[100002];

int main() {
  gets(str);
  int n = strlen(str);
  long long a = 0, b = 0;
  int cnt[2][2] = {0};
  for (int i = n - 1; i >= 0; --i) {
    int c = str[i] - 'a'; 
    a += cnt[c][i % 2 == 0];
    b += cnt[c][i % 2 == 1] + 1;
    cnt[c][i & 1]++;
  }
  cout << a << " " << b << endl;
  return 0;
}