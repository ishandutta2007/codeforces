#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

pair<long long, int> get(const vector<long long>& a) {
  pair<long long, int> ret = make_pair(a[0], 0);
  for (int i = 0; i < a.size(); ++i) {
    ret = min(ret, make_pair(a[i], i));
  }
  return ret;
}

int main() {
  int k, n1, n2, n3, t1, t2, t3;
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  long long ans = 0;
  vector<long long> f1(n1), f2(n2), f3(n3);
  while (k--) {
    auto p1 = get(f1);
    auto p2 = get(f2);
    auto p3 = get(f3);
    long long st = max(p2.first, p3.first - t2);
    st = max(p1.first, st - t1);
    f1[p1.second] = st + t1;
    f2[p2.second] = st + t1 + t2;
    f3[p3.second] = st + t1 + t2 + t3;
    ans = max(ans, st + t1 + t2 + t3);
    // cout << st << endl;
  }
  cout << ans << endl;
  return 0;
}