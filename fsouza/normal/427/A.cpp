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
  int npolice = 0;
  int result = 0;
  int n;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    int ev;
    cin >> ev;
    if (ev == -1) {
      if (npolice > 0) npolice--;
      else result++;
    } else {
      npolice += ev;
    }
  }

  cout << result << endl;

  return 0;
}