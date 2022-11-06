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
  int n, ndigit = 0;

  cin >> n;

  while (n > 0 || ndigit == 0) {
    ndigit++;
    int d = n%10;

    if (d >= 5) {
      cout << "-O";
      d -= 5;
    } else {
      cout << "O-";
    }
    cout << "|";
    for (int i = 0; i < d; i++) cout << "O";
    cout << "-";
    for (int i = 0; i < 4-d; i++) cout << "O";
    cout << endl;

    n /= 10;
  }

  return 0;
}