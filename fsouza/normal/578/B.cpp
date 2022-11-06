#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned long long ulint;

int main() {
  int n, k, x;
  cin >> n >> k >> x;

  vector<ulint> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  ulint result = 0;

  vector<int> nbit(63);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 63; ++j)
      if ((1LL << j) & v[i])
    ++nbit[j];

  for (int i = 0; i < n; ++i) {
    vector<int> co = nbit;
    
    ulint vi = v[i];
    for (int j = 0; j < 63; ++j)
      if ((1LL << j) & vi)
    --nbit[j];
    for (int z = 0; z < k; ++z) vi *= x;
    
    for (int j = 0; j < 63; ++j)
      if ((1LL << j) & vi)
    ++nbit[j];

    ulint res = 0;
    for (int j = 0; j < 63; ++j)
      if (nbit[j] > 0)
    res |= 1LL << j;

    nbit = co;
    
    result = max(result, res);
  }

  cout << result << endl;
  
  return 0;
}