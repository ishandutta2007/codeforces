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

const int N = 1e6 + 7;

bool pr[N];
int good[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 2; i < N; ++i) {
    pr[i] = true;
  }
  for (int i = 2; i < N; ++i) {
    if (pr[i]) {
      for (int j = 2 * i; j < N; j += i) {
        pr[j] = false;
      }
    }
  }
  for (int x = 2; x < N; ++x) {
    if (!pr[x]) {
      ++good[x];
    } else if ((ll)x * x < N) {
      ++good[x * x];
    }
  }
  for (int i = 2; i < N; ++i) {
    good[i] += good[i - 1];
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n - good[n] << '\n';
  }
}