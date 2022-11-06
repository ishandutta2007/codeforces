#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> opens;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    opens[b[i]]++;
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int no = opens[a[i]];
    if (b[i] == a[i])
      no--;
    if (no == 0)
      ret++;
  }
  cout << ret << endl;
  return 0;
}