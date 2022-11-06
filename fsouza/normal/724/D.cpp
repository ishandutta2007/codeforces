#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool possible(const string &s, const string &sorted, int sublen, int size) {
  static vector<bool> isgoodsub;
  const int n = s.size();
  isgoodsub.resize(n);
  const char activelet = sorted[size-1];

  int ngood = 0;
  for (int end = 0; end < n; ++end) {
    int start = end - sublen + 1;
    ngood += (s[end] < activelet);
    if (end - sublen >= 0) ngood -= (s[end - sublen] < activelet);
    if (start >= 0) {
      isgoodsub[start] = (ngood > 0);
    }
  }

  static vector<int> activeidx;
  activeidx.clear();
  for (int i = 0; i < n; ++i)
    if (s[i] == activelet)
      activeidx.push_back(i);
  reverse(activeidx.begin(), activeidx.end());

  int remain = count(sorted.begin(), sorted.begin() + size, activelet);
  int lastchosen = -1;

  for (int start = 0; start + sublen - 1 < n; ++start) {
    const int end = start + sublen - 1;
    if (isgoodsub[start]) continue;
    if (start <= lastchosen) continue;
    if (remain == 0) return false;
    --remain;

    while (!activeidx.empty() && activeidx.back() < start)
      activeidx.pop_back();
    while (activeidx.size() >= 2 && activeidx.end()[-2] <= end)
      activeidx.pop_back();
    if (activeidx.empty()) return false;
    if (activeidx.back() > end) return false;
    lastchosen = activeidx.back();
    activeidx.pop_back();
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int sublen;
  string s;
  cin >> sublen >> s;
  const int n = s.size();

  string sorted = s;
  sort(sorted.begin(), sorted.end());

  int l = 1, r = n;
  while (l < r) {
    int mid = l+(r-l)/2;
    if (possible(s, sorted, sublen, mid)) r = mid;
    else l = mid+1;
  }

  string result = sorted.substr(0, l);
  cout << result << "\n";

  return 0;
}