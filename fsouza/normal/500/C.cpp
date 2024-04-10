#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, m;

  scanf("%d %d", &n, &m);
  
  vector<int> w(n);
  for (int i = 0; i < n; i++) scanf("%d", &w[i]);

  vector<int> shelf;
  int result = 0;
  for (int j = 0; j < m; j++) {
    int put;
    scanf("%d", &put);
    put--;

    for (int i = 0; i < (int)shelf.size(); i++) {
      if (shelf[i] == put) {
	shelf.erase(shelf.begin() + i);
	break;
      }
      result += w[shelf[i]];
    }

    shelf.insert(shelf.begin(), put);
  }

  printf("%d\n", result);

  return 0;
}