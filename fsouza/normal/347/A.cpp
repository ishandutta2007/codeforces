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
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  swap(v[max_element(v.begin(), v.end()) - v.begin()], v[0]);
  swap(v[min_element(v.begin(), v.end()) - v.begin()], v[n-1]);

  sort(v.begin()+1, v.end()-1);

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) cout << " ";
    cout << v[i];
  }
  cout << endl;

  return 0;
}