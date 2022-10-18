#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

int t, n, p;

pair< int, int > fp(int a, int b) {
  return make_pair(min(a, b), max(a, b));
}

void solve() {
  scanf("%d%d", &n, &p);

  set< pair< int, int > > s;

  for (int i = 0; i + 5 <= n; i += 5)
    for (int j = i; j < i + 5; ++j)
      for (int k = i; k < i + 5; ++k)
        if (j != k)
          s.insert(fp(j, k));

  for (int i = n - (n % 5); i < n; ++i)
    for (int j = n - (n % 5); j < n; ++j)
      if (i != j)
        s.insert(fp(i, j));

  if (n % 5 == 1 || n % 5 == 4) {
    s.insert(fp(0, n - 1));
    s.insert(fp(1, n - 1));
  }

  if (n % 5 == 2 || n % 5 == 3) {
    s.insert(fp(0, n - 1));
    s.insert(fp(1, n - 1));
    s.insert(fp(2, n - 2));
  }

  assert(s.size() == 2 * n);

  for (int i = 0; i < n && s.size() < 2 * n + p; ++i)
    for (int j = 0; j < n && s.size() < 2 * n + p; ++j)
      if (i != j && s.find(fp(i, j)) == s.end())
        s.insert(fp(i, j));

  for (auto r : s)
    printf("%d %d\n", r.first + 1, r.second + 1);
}

int main(void)
{
  scanf("%d", &t);
  while (t--) solve();

  return 0;
}