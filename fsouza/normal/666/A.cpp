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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  string s;
  cin >> s;
  s = s.substr(5);
  reverse(s.begin(), s.end());
  int n = s.size();

  set<string> result;

  queue<pair<int, int>> q;
  set<pair<int, int>> mark;

  q.push(make_pair(0, 0));
  mark.insert(make_pair(0, 0));

  while (!q.empty()) {
    pair<int, int> st = q.front(); q.pop();
    int pos = st.first, prevlen = st.second;

    for (int len = 2; len <= 3; ++len) {
      if (pos + len <= n) {
	if (len != prevlen || s.substr(pos, len) != s.substr(pos-prevlen, prevlen)) {
	  result.insert(s.substr(pos, len));

	  pair<int, int> st2 = {pos + len, len};
	  if (st2.first < n && mark.find(st2) == mark.end()) {
	    q.push(st2);
	    mark.insert(st2);
	  }

	}
      }
    }
  }

  set<string> result2;
  for (string str : result) {
    reverse(str.begin(), str.end());
    result2.insert(str);
  }
  result = result2;

  cout << result.size() << "\n";
  for (string str : result)
    cout << str << "\n";

  return 0;
}