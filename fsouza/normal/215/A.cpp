#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int m;
  cin >> m;
  vector<int> b(m);
  for (int j = 0; j < m; j++) cin >> b[j];

  int maxratio = 0, many = 0;
  for (int i = 0; i < n; i++)
    for	(int j = 0; j <	m; j++)
      if (b[j] % a[i] == 0) {
	int v =	b[j] / a[i];
	if (v >	maxratio) {
          many = 0;
          maxratio = v;
	}
	if (v == maxratio)
          many++;
      } 

  cout << many << endl;

  return 0;
}