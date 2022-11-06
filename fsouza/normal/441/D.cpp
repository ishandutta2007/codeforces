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

int count(vector<int> perm, vector<int> &cntof) {
  int ncnt = 0;
  for (int i = 0; i < (int)perm.size(); i++)
    if (perm[i] != -1) {
      for (int j = i, nextj; j != -1; j = nextj) {
	nextj = perm[j];
	perm[j] = -1;
	cntof[j] = ncnt;
      }
      ncnt++;
    }
  return ncnt;
}

int main(int argc, char ** argv)
{
  int n;
  cin >> n;
  vector<int> perm(n);
  for (int i = 0; i < n; i++) cin >> perm[i], perm[i]--;
  int m;
  cin >> m;
  int want = n-m, have;
  vector<int> cntof(n);
  vector<pair <int, int> > swaps;
  vector<int> cntsize(n);

  while ((have = count(perm, cntof)) != want) {
    for (int i = 0; i < have; i++) cntsize[i] = 0;
    for (int i = 0; i < n; i++) cntsize[cntof[i]]++;

    int a, b;

    if (have < want) {
      for (int i = 0; i < have; i++)
	if (cntsize[i] >= 2) {
	  int j = 0;
	  while (cntof[j] != i) j++;
	  a = j; j++;
	  while (cntof[j] != i) j++;
	  b = j; j++;
	  break;
	}
    } else {
      a = 0;
      for (int j = 0; j < n; j++)
	if (cntof[j] != cntof[a]) {
	  b = j;
	  break;
	}
    }

    swaps.push_back(make_pair(a, b));
    swap(perm[a], perm[b]);
  }

  cout << swaps.size() << endl;
  for (int i = 0; i < (int)swaps.size(); i++) {
    if (i-1 >= 0) cout << " ";
    cout << swaps[i].first+1 << " " << swaps[i].second+1;
  }
  cout << endl;

  return 0;
}