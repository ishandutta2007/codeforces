

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
    long long n;
    char s[200000];
    cin  >> n >> s;
    int a = 0;
    long long l = strlen(s);
    for(int i = 0; i<n; i++) {
      if(s[i] == 'I') {
        a++;
      }
    } 
    int v = 0;
    for(int i =0; i<n; i++) {
      if(s[i] != 'F') {
        int k =0;
        if(s[i] == 'I') {
          k++;
        }
        if(a - k <= 0) {
           v++;
        }
      }
    }
    printf("%d", v);
    return 0;
}