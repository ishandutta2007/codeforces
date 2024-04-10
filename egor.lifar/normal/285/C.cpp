
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool let(pair<int, int>a, pair<int, int>b) {
  return  -a.first < -b.first;
}
bool let2(pair<int, int>a, pair<int, int>b) {
  return a.second < b.second;
}

int main() {
  int n, a[300001];
  scanf("%d", &n);
  for(int i =1; i<=n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  long long s =0;
  for(int i =1; i<=n; i++) {
    s = s + abs(a[i] - i);
  }
  cout << s;
  return 0;

     
}