#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

multiset<int> f;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n * n; ++i) {
    int a;
    scanf("%d", &a);
    f.insert(a);
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int v = *f.rbegin();
    f.erase(f.find(v));
    for (int j = 0; j < ans.size(); ++j) {
      f.erase(f.find(gcd(v, ans[j])));
      f.erase(f.find(gcd(v, ans[j])));
    }
    ans.push_back(v);
    if (i) cout << " ";
    cout << v;
  }
  cout << endl;
  return 0;
}