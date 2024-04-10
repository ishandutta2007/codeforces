
// #include <cstdio>
// #include <string.h>


// char s1[10000], s2[10000];

// bool IsDigit(char c) {
// 	if (c >= '0' && c <= '9' ) {
// 		return true;
// 	}
// 	return false;
// }

// char ToUpper(char c) {
// 	if (c >= 'a' && c <= 'z') {
// 		c = c - 'a'+'A';
// 	}
// 	return c;
// }

// char ToLower(char c) {
// 	if (c >= 'A' && c <= 'Z') {
//        c = c - 'A' + 'a'; 
// 	}
// 	return c;
// }

// char ChangeCase(char c) { 
// 	if (ToLower(c) == c) {
// 		return ToUpper(c);
// 	}
//     return ToLower(c);
// }
// bool Compare(char* s1, char* s2) {
// 	int l1 = strlen(s1), l2 = strlen(s2);
// 	if (l1 != l2) {
// 		return false;
// 	}
// 	for (int i = 0; i < l1; i++) {
// 		if (s1[i] != s2[i]) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

// bool Compare2(char* s1, char* s2) {
// 	while (*s1 && *s2) {
// 		if (*s1 != *s2) {
// 			return false;
// 		}
// 		s1++;
// 		s2++;
// 	}
// 	return *s2 == *s1;
// }

// bool Compare3(char* s1, char* s2) {
//      return strcmp(s1, s2) == 0;
// }
// int main() {
//     char c;
//     scanf("%s %s", s1, s2);
//     if (Compare3(s1, s2)) {
// 		printf("yes");	
//     } else {
//     	printf("no");
//     }
    
//     return 0;
// }
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
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int a = 1; a<=n; a++){
    int c = 1;
    for (int b = 1; b<=a; b++)  {
     while (c * c < a * a + b * b && c<n) {
      c += 1;
     }
     if (c * c == a * a + b * b){
        ans += 1;
      }
   }
  }
  printf("%d", ans);
  return 0;
}