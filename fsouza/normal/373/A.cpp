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
  int k;

  cin >> k;

  vector<int> cnt(10, 0);

  char c;
  while (cin >> c)
    if ('0'<= c && c <= '9') {
      int t = c - '0';
      cnt[t]++;
    }
  
  bool ok = true;
  for (int i =0; i < 10; i++) if (cnt[i] > 2*k) ok = false;

  if (ok) cout << "YES"<< endl;
  else cout << "NO" << endl;

  return 0;
}