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
  int k;
  cin >> k;
  vector<int> d(k);
  for (int i = 0; i < k; i++) cin >> d[i];

  vector<int> ret;
  if (count(d.begin(), d.end(), 0)) ret.push_back(0);
  if (count(d.begin(), d.end(), 100)) ret.push_back(100);
  
  bool found = false;

  for (int i = 0; i < (int)d.size(); i++) {
    if (0 < d[i] && d[i] < 100 && d[i]%10 == 0) {
      ret.push_back(d[i]);
      found = true;
      break;
    }
  }
  for (int i = 0; i < (int)d.size(); i++) {
    if (0 < d[i] && d[i] < 100 && (d[i]/10)%10 == 0) {
      ret.push_back(d[i]);
      found = true;
      break;
    }
  }

  if (!found)
    for (int i = 0; i < (int)d.size(); i++) {
      if (0 < d[i] && d[i] < 100) {
	ret.push_back(d[i]);
	break;
      }
    }

  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); i++) {
    if (i-1 >= 0) cout << " ";
    cout << ret[i];
  }
  cout << endl;

  return 0;
}