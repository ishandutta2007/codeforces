#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
  // int n, a[100000];
  // scanf("%d", &n);
  // long long s = 0;
  // for(int i = 0; i < n; i++){
  // 	scanf("%d", &a[i]);
  // }
  // for(int i = 0; i < n; i++){
  // 	 s += a[i];
  // }


  // long long k = s / 2;
  // if(s % 2 == 1){
  // 	printf("0\n");
  // 	return 0;
  // }
  // long long p = 0;
  // int r = 0;
  // for(int i = 0; i < n - 1; i++){
  // 	p += a[i];
  // 	if(p == k){
  // 		r++;
  // 	}
  // }
  // printf("%d\n", r);

  string s[1000];
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i< n; i++){
  	cin >> s[i];
  	if(i > 0){
  		if(s[i] == s[i-1]){
  			printf("NO\n");
  			return 0;
  		}
  	}
  }	
  for(int i = 0; i<n; i++){
  	bool b = true;
  	for(int j = 1; j<m; j++){
  		if(s[i][j] != s[i][j-1]){
  			b = false;
  			break;
  		}
  	}
  	if(b == false){
  		printf("NO\n");
  		return 0;
  	}
  }
  printf("YES\n");
  return 0;
}