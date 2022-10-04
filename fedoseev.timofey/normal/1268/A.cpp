#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  vector <int> b;
  for (int i = 0; i < n; ++i) b.push_back(a[i % k]);
  bool fl = (b >= a); 
  if (!fl) {
    for (int i = k - 1; i >= 0; --i) {
      if (a[i] != 9) {
        ++a[i];
        for (int j = i + 1; j < k; ++j) {
          a[j] = 0;
        }
        break;
      }
    }
    b.clear();
    for (int i = 0; i < n; ++i) b.push_back(a[i % k]);
  }
  cout << n << '\n';
  for (int i = 0; i < n; ++i) cout << b[i];
}