#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>
#include <cmath>

using namespace std;


int main()
{  
    int n, a[1000];
    scanf("%d", &n);
    for(int i =0; i<n; i++){
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int b = 0;
    int s = 0;
    for(int i = 0; i<n; i++){
       if(i > 0 && a[i] == a[i - 1] || a[i] == 0){
        b++;
       } else {
        s += b / 2;
        b = 1;
       }
    }
    s += b / 2;
    s = s / 2;
    printf("%d\n", s);
    return 0;

}