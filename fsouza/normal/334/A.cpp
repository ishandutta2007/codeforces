#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int n;
  cin >> n;
  int l = 0, r = n*n-1;

  for (int i = 0; i < n; i++) {
    vector<int> ans;
    for (int j = 0; j < n/2; j++) ans.push_back(l++);
    for (int j = 0; j < n/2; j++) ans.push_back(r--);
    for (int k = 0; k < (int)ans.size(); k++) {
      if (k-1 >= 0) cout << " ";
      cout << ans[k]+1;
    }
    cout << endl;
  }

  return 0;
}