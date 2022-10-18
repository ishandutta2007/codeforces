#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];

int main() {
  int n, s = 0;
  long long total = 0, mx = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    s = (s + arr[i]) % 2;
    total += arr[i];
    mx = max(mx, (long long) arr[i]);
  }
  cout << ((s == 0 && (2 * mx <= total)) ? "YES" : "NO") << endl;
  return 0;
}