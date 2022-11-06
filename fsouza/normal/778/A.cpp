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

bool is_substring(string &small, string &big, vector<int> &perm, int many,
                  vector<bool> &is_removed, vector<vector<int>> &nextlet) {
  const int n = big.size();
  fill(is_removed.begin(), is_removed.end(), false);
  for (int i = 0; i < many; ++i)
    is_removed[perm[i]] = true;

  int i = 0;
  for (int j = 0; j < (int)small.size(); ++j) {
    int let = small[j] - 'a';
    while (i < n && (is_removed[i] || big[i] != 'a' + let))
      i = nextlet[let][i + 1];
    if (i == n)
      return false;
    ++i;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string start, end;
  cin >> start >> end;
  int n = start.size();
  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    cin >> perm[i], --perm[i];

  vector<vector<int>> nextlet(26, vector<int>(n+1));
  for (int let = 0; let < 26; ++let) {
    nextlet[let][n] = n;
    for (int i = n-1; i >= 0; --i) {
      if (start[i] == 'a' + let) nextlet[let][i] = i;
      else nextlet[let][i] = nextlet[let][i+1];
    }
  }

  vector<bool> is_removed(n);

  int left = 0, right = start.size() - end.size();
  while (left < right) {
    int m = left + (right - left + 1) / 2;
    if (is_substring(end, start, perm, m, is_removed, nextlet))
      left = m;
    else
      right = m - 1;
  }

  printf("%d\n", left);

  return 0;
}