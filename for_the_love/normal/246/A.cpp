#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, i;
    scanf("%d", &n);
    if (n < 3){
        printf("-1\n");
        return 0;
    }
    printf("3 2 ");
    for (i = 3; i <= n; i++){
        printf("1 ");
    }
    printf("\n");
    return 0;
}