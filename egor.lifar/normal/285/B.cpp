
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
  int n, s, t, p[100000];
  scanf("%d %d %d", &n, &s, &t);
  for(int i =1; i<=n; i++) {
    scanf("%d", &p[i]);
  }
  int r = s;
  if(s == t) {
    printf("0\n");
    return 0;
  }
  s = p[s];
  int k = 0;
  while(s != r) {
     k+=1;
     if(s == t) {
      printf("%d\n", k);
      return 0;
     }
     s = p[s];
  }
  printf("-1\n");
  
  return 0;

     
}