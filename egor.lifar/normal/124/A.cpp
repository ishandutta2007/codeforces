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
    int n, a, b, k = 0;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = a; i < n; i++){
       if(n - i - 1 <= b){
        k++;
       }
    }
    printf("%d", k);
    return 0;

}