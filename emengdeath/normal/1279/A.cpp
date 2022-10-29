#include <algorithm>
#include <cstdio>
#include <iostream>
using  namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        int a[3];
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        if (a[0] + a[1] >= a[2] - 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}