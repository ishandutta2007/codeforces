#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{  
    int n, a[1000];
    scanf("%d", &n);
    int s = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
      s+=a[i];
    }
    for(int i = 0; i < n; i++){
      if(a[i] % 2 == s % 2){
        k++;
      }
    }
    printf("%d\n", k);
    return 0;
}