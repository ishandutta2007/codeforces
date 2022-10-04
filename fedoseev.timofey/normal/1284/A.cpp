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
#include <iomanip>
#include <cassert>
#include <complex>
 
using namespace std;
 
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector <string> t(m);
  for (int i = 0; i < m; ++i) cin >> t[i];
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    --x;
    cout << s[x % n] + t[x % m] << '\n';
  }
}