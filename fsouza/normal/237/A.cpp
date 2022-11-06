#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n;

  cin >> n;

  int result = 0;
  int last = -1, many = 0;

  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    int t = 60*h + m;
    
    if (t != last) {
      result = max(result, many);
      many = 0;
      last = t;
    }

    many++;
  }

  result = max(result, many);
  many = 0;
  last = -1;

  cout << result << endl;

  return 0;
}