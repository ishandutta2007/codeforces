#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    int n, a[5000];
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int k = 0;
    for(int j = 1; j<=n; j++){
       for(int i = 0; i<n; i++){
          if(a[i] == j){
            k++;
            break;
          }
        }
    }
    printf("%d", n-k);
    return 0;
}