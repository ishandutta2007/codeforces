#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  int mint = *min_element(t.begin(), t.end());
  int many = count(t.begin(), t.end(), mint);

  if (many > 1) printf("Still Rozdil\n");
  else printf("%d\n", (int)(min_element(t.begin(), t.end())-t.begin()+1));
  
  return 0;
}