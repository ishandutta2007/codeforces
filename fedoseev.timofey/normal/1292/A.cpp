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
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif  
  int n, q;
  cin >> n >> q;
  int cnt = 0;
  vector <vector <int>> bl(2, vector <int> (n));
  for (int i = 0; i < q; ++i) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    cnt -= (bl[r][c] && bl[r ^ 1][c]);
    if (c - 1 >= 0) cnt -= (bl[r][c] && bl[r ^ 1][c - 1]);
    if (c + 1 < n) cnt -= (bl[r][c] && bl[r ^ 1][c + 1]);
    bl[r][c] ^= 1;
    cnt += (bl[r][c] && bl[r ^ 1][c]);
    if (c - 1 >= 0) cnt += (bl[r][c] && bl[r ^ 1][c - 1]);
    if (c + 1 < n) cnt += (bl[r][c] && bl[r ^ 1][c + 1]);
    cout << (cnt == 0 ? "Yes" : "No") << '\n';
  }
}