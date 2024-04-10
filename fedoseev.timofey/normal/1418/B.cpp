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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector <int> l(n);
    vector <int> p;
    for (int i = 0; i < n; ++i) {
      cin >> l[i];
      if (l[i] == 0) {
        p.push_back(i);
      }
    }
    vector <int> st = p;
    sort(p.begin(), p.end(), [&] (int i, int j) {
      return a[i] > a[j];
    });
    vector <int> nw = a;
    for (int i = 0; i < (int)st.size(); ++i) {
      nw[st[i]] = a[p[i]]; 
    }
    for (int i = 0; i < n; ++i) cout << nw[i] << ' ';
    cout << '\n';
  }
}