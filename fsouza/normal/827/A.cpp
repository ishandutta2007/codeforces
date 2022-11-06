#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxsize = 2000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string result(maxsize, 'a');
  vector<bool> defined(maxsize, false);
  vector<int> next_undefined(maxsize);
  iota(next_undefined.begin(), next_undefined.end(), 0);
  function<int(int)> get_next_undefined = [&](int pos) {
    if (pos == maxsize || !defined[pos]) return pos;
    else return next_undefined[pos] = get_next_undefined(next_undefined[pos]);
  };
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    int nrep;
    cin >> nrep;
    for (int rep = 0; rep < nrep; ++rep) {
      int pos;
      cin >> pos, --pos;
      for (int k = get_next_undefined(pos);
           k < pos + (int)str.size();
           k = get_next_undefined(k)) {

        result[k] = str[k - pos];
        defined[k] = true;
        next_undefined[k] = k + 1;
      }
    }
  }
  int last_defined = 0;
  for (int i = 1; i < maxsize; ++i)
    if (defined[i])
      last_defined = i;
  result.resize(last_defined + 1);
  cout << result << "\n";
  return 0;
}