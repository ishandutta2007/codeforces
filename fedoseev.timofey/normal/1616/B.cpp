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
    string s;
    cin >> s;
    int uk = 0;
    while (uk + 1 < n && s[uk + 1] < s[uk]) ++uk;
    if (uk > 0) while (uk + 1 < n && s[uk + 1] <= s[uk]) ++uk;
    string a = s.substr(0, uk + 1);
    string b = a;
    reverse(b.begin(), b.end());
    cout << a + b << '\n';
  }   
}