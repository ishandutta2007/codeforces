#include <bits/stdc++.h>

#define MAX 200
int arr[MAX];

int main(void)
{
    int T;
    scanf("%d", &T);
    int i;
    for(i=1;i<=T;i++){
        scanf("%d", &arr[i]);
    }
    int j;
    for(i=1;i<=T;i++){
        for(j=1;j<=arr[i];j++){
            printf("1 ");
        }
        printf("\n");
    }
    return 0;
}