#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long lint;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  int n;
  multiset<int> val;
  vector<int> ret;
  
  scanf("%d", &n);
  for (int i = 0; i < n*n; ++i) {
    int v;
    scanf("%d", &v);
    val.insert(v);
  }

  for (int i = 0; i < n; ++i) {
    int last = *val.rbegin();

    val.erase(val.find(last));
    for (int prev : ret) {
      int g = gcd(last, prev);
      val.erase(val.find(g));
      val.erase(val.find(g));
    }

    ret.push_back(last);
  }

  sort(ret.begin(), ret.end());

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", ret[i]);
  }
  printf("\n");
  
  return 0;
}