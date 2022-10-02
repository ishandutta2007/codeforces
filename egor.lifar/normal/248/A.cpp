
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
  int n, l[10000], r[10000];
  scanf("%d", &n);
  for(int i =0; i<n; i++) {
     scanf("%d %d", &l[i], &r[i]);
  }
  int s1 = 0;
  for(int i =0; i<n; i++) {
      s1+=abs(l[i] - 1);
  }
  int s2= 0;
  for(int i =0; i<n; i++) {
      s2+=l[i];
  }
  int s = min(s1, s2);
  int t1 = 0;
  for(int i =0; i<n; i++) {
      t1+=abs(r[i] - 1);
  }
  int t2= 0;
  for(int i =0; i<n; i++) {
      t2+=r[i];
  }
  int p = min(t1, t2);
  int k = p+s;
  printf("%d", k);
  return 0;
}