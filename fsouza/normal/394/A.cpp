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
  int st = 0;
  int v[3] = {0,0,0};

  char c;
  while (cin >> c) {
    if (c == '|') v[st]++;
    if (c == '+') st = 1;
    if (c == '=') st = 2;
  }
  
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (i != j && v[i] <= 1) continue;
      int v2[3] = {v[0], v[1], v[2]};
      v2[i]--, v2[j]++;
      if (v2[0] + v2[1] == v2[2]) {
	for (int k = 0; k < v2[0]; k++) cout << "|";
	cout << "+";
	for (int k = 0; k < v2[1]; k++) cout << "|";
	cout << "=";
	for (int k = 0; k < v2[2]; k++) cout << "|";
	cout << endl;
	return 0;
      }
    }

  cout << "Impossible" << endl;

  return 0;
}