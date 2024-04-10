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
  int n;
  cin >> n;
  ll ans = 0;
  vector <int> st;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ans += x / 2;
    x %= 2;
    if (x) {
      if (!st.empty() && (i - st.back()) % 2 == 1) {
        ++ans;
        st.pop_back();
      } else {
        st.push_back(i);
      }
    }
  }
  cout << ans << '\n';
}