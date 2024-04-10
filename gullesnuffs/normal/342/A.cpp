#include <stdio.h>

using namespace std;

int a[8];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        int j;
        scanf("%d", &j);
        ++a[j];
    }
    if(a[7] || a[5] || a[3] > a[6] || a[1] != n/3 || a[4]+a[6] != n/3){
        printf("-1\n");
        return 0;
    }
    while(a[3]){
        printf("1 3 6\n");
        --a[3];
        --a[1];
        --a[6];
    }
    while(a[6]){
        printf("1 2 6\n");
        --a[2];
        --a[1];
        --a[6];
    }
    while(a[4]){
        printf("1 2 4\n");
        --a[2];
        --a[1];
        --a[4];
    }
    return 0;
}