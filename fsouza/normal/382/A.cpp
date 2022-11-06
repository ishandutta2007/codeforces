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
  string l1;
  cin >> l1;
  string a = l1.substr(0, find(l1.begin(), l1.end(), '|') - l1.begin());
  string b = l1.substr(find(l1.begin(), l1.end(), '|') - l1.begin()+1, l1.size());
  string c;
  cin >> c;

  for (int pa = 0; pa <= (int)c.size(); pa++) {
    int pb = c.size() - pa;
    if (a.size() + pa == b.size() + pb) {
      for (int i = 0; i < pa; i++) a += string(1, c[i]);
      for (int i = 0; i < pb; i++) b += string(1, c[c.size()-1-i]);
      cout << a << "|" << b << endl;
      return 0;
    }
  }
  
  cout << "Impossible" << endl;

  return 0;
}