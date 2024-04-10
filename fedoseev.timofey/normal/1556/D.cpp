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
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <int> vals;
  for (int i = 0; i < 3; ++i) {
    cout << "and " << i + 1 << ' ' << (i + 1) % 3 + 1 << endl;
    int res;
    cin >> res;
    vals.push_back(res);
    cout << "or " << i + 1 << ' ' << (i + 1) % 3 + 1 << endl;
    cin >> res;
    vals.push_back(res);
  }
  vector <int> ar(n);
  for (int bt = 0; bt < 30; ++bt) {
    for (int a = 0; a <= 1; ++a) {
      for (int b = 0; b <= 1; ++b) {
        for (int c = 0; c <= 1; ++c) {
          vector <int> cval;
          cval.push_back(a & b);
          cval.push_back(a | b);
          cval.push_back(b & c);
          cval.push_back(b | c);
          cval.push_back(a & c);
          cval.push_back(a | c);
          bool ok = true;
          for (int i = 0; i < 6; ++i) {
            ok &= ((vals[i] >> bt) & 1) == cval[i];
          }
          if (ok) {
            ar[0] |= a << bt;
            ar[1] |= b << bt;
            ar[2] |= c << bt;
          }
        }
      }
    }
  }
  for (int i = 3; i < n; ++i) {
    cout << "and " << 1 << ' ' << i + 1 << endl;
    int vand;
    cin >> vand;
    cout << "or " << 1 << ' ' << i + 1 << endl;
    int vor;
    cin >> vor;
    for (int j = 0; j < 30; ++j) {
      if (ar[0] & (1 << j)) {
        if (vand & (1 << j)) ar[i] |= 1 << j;
      } else {
        if (vor & (1 << j)) ar[i] |= 1 << j;
      }
    }   
  }   
  sort(ar.begin(), ar.end());
  cout << "finish " << ar[k - 1] << endl;
}