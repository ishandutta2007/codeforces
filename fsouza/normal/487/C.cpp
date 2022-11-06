#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

typedef long long lint;

using namespace std;

int modpow(int x, int y, int m) {
  if (y == 0) return 1;
  int k = modpow(x, y/2, m); k = (lint)k*k % m;
  if (y%2) return (lint)k*x % m;
  return k;
}

bool generates(int g, int p) {
  for (int d = 1; d*d <= p-1; d++)
    if ((p-1)%d == 0) {
      if (d > 1 && modpow(g, (p-1)/d, p) == 1) return false;
      if (d < p-1 && modpow(g, d, p) == 1) return false;
    }
  return true;
}

int main() {
  int n;

  scanf("%d", &n);

  if (n == 1) {
    printf("YES\n1\n");
    return 0;
  } else if (n == 2) {
    printf("YES\n1\n2\n");    
    return 0;
  } else if (n == 4) {
    printf("YES\n1\n3\n2\n4\n");
    return 0;
  }

  bool prime = true;
  for (int i = 2; i * i <= n; i++)
    if (n%i == 0) {
      prime = false;
      break;
    }
  
  if (!prime) printf("NO\n");
  else {
    printf("YES\n");

    int g;
    for (g = 1; g < n; g++)
      if (generates(g, n))
	break;

    assert(g < n);

    vector<int> values(n-1);
    values[0] = 1;
    for (int i = 1; i < n-1; i++)
      values[i] = ((lint)values[i-1] * g) % n;

    vector<int> ret;

    for (int i = 0; i < (n-1)/2; i++) {
      ret.push_back(values[((n-1) - 2*i) % (n-1)]);
      ret.push_back(values[2*i+1]);
    }
    ret.push_back(n);

    vector<int> prefix;
    int m = 1;
    for (int i = 0; i < (int)ret.size(); i++) {
      printf("%d\n", ret[i]);
      m = (lint)m * ret[i] % n;
      prefix.push_back(m);
    }

    sort(prefix.begin(), prefix.end());
    assert(unique(prefix.begin(), prefix.end()) == prefix.end());
  }

  return 0;
}