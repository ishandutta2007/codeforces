#include <iostream>
#include <cstdio>
#include <iomanip>
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
  vector<double> prob(n);
  for (int i = 0; i < n; i++) {cin >> prob[i];}

  sort(prob.rbegin(), prob.rend());

  double ret = 0.0;
  double p = 1, s = 0;
  
  for (int i = 0; i < n; i++) {
    p *= (1.0 - prob[i]);
    s += prob[i] / (1.0 - prob[i]);
    if (fabs(prob[i]-1.0) < 1e-8) {
      ret = 1.0;
      break;
    }
    ret = max(ret, p * s);
  }

  cout << setprecision(20) << ret << endl;

  return 0;
}