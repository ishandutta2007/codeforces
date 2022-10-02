#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{  
    int n, k, a[1001];
    scanf("%d %d", &n, &k);
    int b[1001];
    for(int i = 1; i<=n*k; i++){
        b[i] = 0;
    }
    for(int i = 1; i <= k; i++){
        scanf("%d", &a[i]);
        b[a[i]] = 1;
    }
    for(int i = 1; i<=k; i++){
       printf("%d ", a[i]);
       int t = 1;
       int j = 1;
       while(t < n){
        if(b[j] == 0){
            t++;
            printf("%d ", j);
            b[j] = 1;
        }
        j++;
       }
       printf("\n");
    }
    
    return 0;
}