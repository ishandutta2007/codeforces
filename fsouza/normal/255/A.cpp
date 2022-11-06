#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  int n;
  cin >> n;
  int many[3] = {0};
  const char* names[3] = {"chest","biceps","back"};

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    many[i%3] += v;
  }

  int mi = max_element(many, many+3)-many;

  cout << names[mi] << endl;

  return 0;
}