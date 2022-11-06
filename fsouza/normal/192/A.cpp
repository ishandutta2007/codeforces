#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n;

  scanf("%d", &n);
  
  vector<int> tri;

  for (int k = 1; k*(k+1)/2 <= n; k++)
    tri.push_back(k*(k+1)/2);

  bool ok = false;

  int j = tri.size()-1;
  for (int i = 0; i < (int)tri.size(); i++) {
    while (j >= 0 && tri[i] + tri[j] > n) j--;
    if (j >= 0 && tri[i] + tri[j] == n) {
      ok = true;
      break;
    }
  }

  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}