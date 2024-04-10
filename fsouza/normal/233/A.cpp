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

  if (n%2) cout << -1 << endl;
  else {
    for (int i = 0; i < n/2; i++) {
      if (i-1 >= 0) cout << " ";
      cout << 2*i+2 << " " << 2*i+1;
    }
    cout << endl;
  }

  return 0;
}