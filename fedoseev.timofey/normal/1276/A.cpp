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
    vector <int> ans;
    int n = s.size();
    for (int i = 0; i + 2 < n; ++i) {
      if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
        ans.push_back(i + 1);
      } 
      if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
        if (i + 3 < n && s[i + 3] == 'o') ans.push_back(i + 1);
        else {
          ans.push_back(i + 2);
          i += 2;
        }
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    cout << '\n';
  }
}