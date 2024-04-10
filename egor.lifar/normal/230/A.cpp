
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
 
using namespace std;
 
 
 
int main() {                          
    int s, n;
    scanf("%d %d", &s, &n);    
    vector<pair<int, int> > v(n);
    for(int i =0; i<n; i++) {
      scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    int i =0;
    while(s > v[i].first && i<n) {
      s+=v[i].second;
      i++;
    }
    if(i == n) {
      printf("YES");
    } else {
      printf("NO");
    }
    return 0;
}