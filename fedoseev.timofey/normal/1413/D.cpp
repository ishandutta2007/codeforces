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
  int n;
  cin >> n;
  vector <int> op(2 * n);
  vector <int> st;
  for (int i = 0; i < 2 * n; ++i) {
    char c;
    cin >> c;
    if (c == '+') {
      st.push_back(i);
    } else {
      int x;
      cin >> x;
      op[i] = -x;
      if (st.empty()) {
        cout << "NO\n";
        return 0;
      }
      op[st.back()] = x;
      st.pop_back();
    }
  }
  vector <int> ord;
  set <int> have;
  for (int i = 0; i < 2 * n; ++i) {
    if (op[i] > 0) {
      ord.push_back(op[i]);
      have.insert(op[i]);
    } else {
      if (have.empty() || *have.begin() != -op[i]) {
        cout << "NO\n";
        return 0;
      }
      have.erase(have.begin());
    }
  }
  cout << "YES\n";
  for (int x : ord) {
    cout << x << ' ';
  }
}