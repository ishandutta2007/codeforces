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
  vector<int> mask(n);
  for (int i = 0; i < n; i++) {
    char c, v;
    cin >> c >> v;
    const char* aa = "RGBYW";
    const char* bb = "12345";
    int a = strchr(aa, c) - aa;
    int b = strchr(bb, v) - bb;
    mask[i] = ((1<<a) | (1<<(b+5)));
  }
  
  sort(mask.begin(), mask.end());
  n = unique(mask.begin(), mask.end()) - mask.begin();
  mask.resize(n);
  
  int result = INF;

  vector<int> mask2;
  for (int tell = 0; tell < (1<<10); tell++) {
    mask2.clear();
    for (int i = 0; i < n; i++) mask2.push_back(mask[i] & tell);
    sort(mask2.begin(), mask2.end());
    bool ok = true;
    for (int i = 0; i+1 < n; i++)
      if (mask2[i] == mask2[i+1])
	ok = false;
    if(ok) result = min(result, __builtin_popcount(tell));
  }

  cout << result << endl;
  
  return 0;
}