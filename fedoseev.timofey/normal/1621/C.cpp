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
    int n;
    cin >> n;
    vector<int> ans(n);
    set<int> have;
    int cnt_qr = 0;

    auto ask = [&](int i) {
      ++cnt_qr;
      int ret;
      cout << "? " << i + 1 << endl;
      cin >> ret; 
      --ret;
      return ret;
    };
    
    for (int i = 0; i < n; ++i) {
      vector<int> ord;
      int x = ask(i); 
      while (!have.count(x)) {
        ord.push_back(x);
        have.insert(x);
        x = ask(i);
      }
      if (!ord.empty()) {
        for (int i = 0; i < (int)ord.size(); ++i) {
          int j = (i + 1) % (int)ord.size();
          ans[ord[i]] = ord[j];
        }
      }
    }
    cout << "! ";
    for (auto x : ans) cout << x + 1 << ' ';
    cout << endl;
  }
}