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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> before(26, -1), after(26, -1);
  vector<bool> mark(26, false), exist(26, false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < (int)s.size(); ++j) {
      int a = s[j]-'a';
      if (j+1 < (int)s.size()) {
	int b = s[j+1]-'a';
	before[b] = a;
	after[a] = b;
      }
      exist[a] = true;
    }
  }

  for (int i = 0; i < 26; ++i)
    if (exist[i] && !mark[i] && before[i] == -1)
      for (int j = i; j != -1; j = after[j])
	printf("%c", 'a'+j);
  printf("\n");

  return 0;
}