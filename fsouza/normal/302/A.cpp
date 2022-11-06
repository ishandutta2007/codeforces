#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  cin >> n >> m;
  int nneg = 0, npos = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v == -1) nneg++;
    else npos++;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    int many = r-l+1;
    if (many%2 || nneg < many/2 || npos < many/2) cout << "0" << endl;
    else cout << "1" << endl;
  }
  return 0;
}