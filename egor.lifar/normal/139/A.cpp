#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    int  n, a[7], k, p;
    scanf("%d", &n);
    for(int i = 1; i < 7; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &a[0]);
    k = 0;
    p = 0;
    while(k < n){
        p++;
        k += a[p % 7]; 
    }
    if(p % 7 == 0){
        printf("7\n");
    } else {
        printf("%d\n", p % 7);
    }
    
    return 0;
}