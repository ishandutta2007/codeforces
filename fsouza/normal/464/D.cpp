#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  const int maxlevel = 600;

  vector<double> fi(maxlevel+1, 0.0), oldfi(maxlevel+1);

  for (int i = 1; i <= n; i++) {
    fi.swap(oldfi);

    for (int l = 1; l <= maxlevel; l++) {
      fi[l] = 0.0;
      fi[l] += (k-1.0)/(1.0*k) * oldfi[l];

      double p2 = 0.0;
      
      if (l+1 <= maxlevel)
	p2 += (1.0 / (l+1.0)) * (l + oldfi[l+1]);
      else
	p2 += (1.0 / (l+1.0)) * (l + (    (l+1 + 1)/2.0 * (i-1.0) / (1.0 * k)    ));

      p2 += (1.0 * l) / (l + 1.0) * oldfi[l];

      p2 += l / 2.0;

      fi[l] += p2 * (1.0/k);
    }
  }
  
  double ret = 1.0 * k * fi[1];

  printf("%.10f\n", ret);

  return 0;
}