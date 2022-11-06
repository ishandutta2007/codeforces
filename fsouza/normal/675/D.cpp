#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> vals;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    vals.emplace_back(v, i);
  }
  sort(vals.begin(), vals.end());

  vector<int> result(n);
  stack<pair<int, int>> st;

  for (pair<int, int> &v : vals) {
    if (!st.empty() && st.top().second > v.second) {
      pair<int, int> last;
      do {
	pair<int, int> c = st.top(); st.pop();
	if (!st.empty()) result[c.second] = st.top().first;
	else result[c.second] = INT_MIN;
	last = c;
      } while (!st.empty() && st.top().second > v.second);
      result[last.second] = v.first;
    }
    st.push(v);
  }
  while (!st.empty()) {
    pair<int, int> v = st.top(); st.pop();
    if (st.empty()) result[v.second] = INT_MIN;
    else result[v.second] = st.top().first;
  }

  for (int i = 1; i < n; ++i) {
    if (i > 1) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}