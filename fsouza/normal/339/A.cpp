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
  vector<char> v;
  cin >> c;
  v.push_back(c);
  char c2;
  while (cin >> c2 >> c) {
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  cout << v[0];
  for (int i = 1; i < (int)v.size(); i++)
    cout << "+" << v[i];
  cout << endl;

  return 0;
}