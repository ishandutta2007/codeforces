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

int main() {
  int nline;
  scanf("%d", &nline);
  vector<int> values(nline);
  for (int &v : values) scanf("%d", &v);

  string line;
  getline(cin, line);

  bool result = true;
  for (int i = 0; i < nline; ++i) {
    getline(cin, line);
    istringstream iss(line);
    string word;
    int nhave = 0;
    while (iss >> word) {
      for (int j = 0; j < (int)word.size(); ++j) {
        char c;
        if (strchr("aeiouy", word[j]) != NULL)
          ++nhave;
      }
    }
    if (nhave != values[i]) result = false;
  }

  if (result) printf("YES\n");
  else printf("NO\n");

  return 0;
}