

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<vector<int> > v;

int n;
bool used[101]; 
int a[101][101];
int s = 0;
int dfs(int x) {
  int p = 1;
  if (used[x]) {
    p = 1;
    return 0;
  }
  used[x] = true;
  v[s].push_back(x);
  for (int i =0; i<n; i++)  {
    if(a[x][i] == 1){
      p+=dfs(i);
    }  
  }
  return p;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for(int i =0; i<n; i++) {
    used[i] = false;
  }
  for(int i =0; i<m; i++ ) {
    int b, c;
    scanf("%d %d", &b, &c );
    a[b - 1][c - 1] = 1;
    a[c - 1][b - 1] = 1;
  }
  for(int i=0; i<n; i++) {
    if(used[i]  == false) {
      vector <int> m;
      v.push_back(m);
      if(dfs(i)  > 3) {
        printf("-1");
        return 0;
      } 
      s+=1;
    }
  }
  int b[4];
  b[0] = 0;
  b[1] = 0;
  b[2] = 0;
  b[3] = 0;
  for(int i = 0; i<s; i++) {
    b[v[i].size()] +=1;
  }
  if ((b[2]>b[1]) || (b[1]-b[2]) % 3 != 0) {
    printf("-1");
    return 0;
  }
  int c[100];
  for(int i =0; i<n; i++) {
    c[i] = 0;
  }
  for(int i=0; i<s; i++) {
    if(v[i].size() == 3) {
      printf("%d %d %d\n", v[i][0]+1, v[i][1]+1, v[i][2]+1);
    }
    if(v[i].size() == 2) {
      for(int j =0; j<s; j++) {
        if(v[j].size() == 1 && c[j] == 0) {
          c[j] = 1;
          printf("%d %d %d\n", v[j][0]+1, v[i][0]+1, v[i][1]+1);
          break;
        }
      }
    }
  }
  int l = 0;
  for(int i = 0; i<s; i++) {
    if(c[i] == 0 && v[i].size() == 1) {
      if(l % 3 == 0 && l != 0) {
        printf("\n");
      }
      printf("%d ", v[i][0]+1);
      l+=1;
    }
  }
  return 0;
}