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
  string color = "blue";
  bool locked = false;
  while (n--) {
    string s;
    cin >> s;
    if (s == "lock") {
      locked = true;
    } else if (s == "unlock") {
      locked = false;
    } else if (!locked) {
      color = s;
    }
  }
  cout << color << '\n';
}