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
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << "0\n";
    } else if (c == d) {
      cout << "1\n";
    } else if (c % 2 == d % 2) {
      cout << "2\n";
    } else {
      cout << "-1\n";
    }
  }
}