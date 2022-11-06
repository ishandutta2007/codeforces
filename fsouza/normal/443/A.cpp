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
  char c;

  set <char> s;

  cin >> c;
  while (true) {
    cin >> c;
    if (c == '}') break;
    s.insert(c);
    cin >> c;
    if (c == '}') break;
  }

  cout << s.size() << endl;

  return 0;
}