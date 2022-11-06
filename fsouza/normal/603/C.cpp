#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int grundy(int n, int k) {
  if (n == 0) return 0;
  else if (n%2 == 1) {
    if (k%2 == 0) return n == 1;
    else return n == 1 || n == 3;
  } else {
    vector<int> adj;
    adj.push_back(grundy(n-1, k));
    if (k%2 == 0) adj.push_back(0);
    else adj.push_back(grundy(n/2, k));
    sort(adj.begin(), adj.end());

    int result;
    if (adj.empty() || adj.front() > 0) result = 0;
    else {
      for (int i = 0; i < (int)adj.size(); ++i)
	if (i == (int)adj.size()-1 || adj[i]+1 < adj[i+1]) {
	  result = adj[i]+1;
	  break;
	}
    }
    return result;
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int resultxor = 0;
  for (int i = 0; i < n; ++i) {
    int size;
    scanf("%d", &size);
    resultxor ^= grundy(size, k);
  }

  if (resultxor) printf("Kevin\n");
  else printf("Nicky\n");
  
  return 0;
}