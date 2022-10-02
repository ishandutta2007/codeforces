#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;

 
int gx[1001], gy[1001];
int hx[1001], hy[1001];
int a[1001][1001];


int main() {                          
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i =1; i<=n; i++){
    for(int j =1; j<=m; j++){
      scanf("%d", &a[i][j]);
      gx[j] = j;
      hx[j] = j;
    }
    gy[i] = i;
    hy[i] = i;
  }
  for(int g =0; g<k; g++){
    int x, y;
    char c;
    scanf(" %c %d %d", &c, &x, &y);
    if(c == 'g'){
      printf("%d\n", a[hy[x]][hx[y]]);
    } else {
      if(c == 'r') {
        int a1 = hy[x];
        gy[a1] = y;
        int b = hy[y];
        gy[b] = x;
        hy[y] = a1;
        hy[x] = b; 
      } else {
        int a1 = hx[x];
        gx[a1] = y;
        int b = hx[y];
        gx[b] = x;
        hx[y] = a1;
        hx[x] = b;
      }
    }
  }
  return 0;
}