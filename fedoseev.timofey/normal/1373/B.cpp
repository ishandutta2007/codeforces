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
    string s;
    cin >> s;
    int n = s.size();
    vector <char> st;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (st.empty() || st.back() == s[i]) {
        st.push_back(s[i]);
      } else {
        ++cnt;
        st.pop_back();
      }
    } 
    if (cnt % 2 == 1) {
      cout << "DA\n";
    } else {
      cout << "NET\n";
    }
  }
}