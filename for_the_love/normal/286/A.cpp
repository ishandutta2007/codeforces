#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, a[100005];
int main(){
    scanf("%d", &n);
    if (n % 4 != 0 && n % 4 != 1){
        printf("-1\n");
        return 0;
    }
    for (i = 1; i <= n / 4; i++){
        a[(i - 1) * 2 + 1] = i * 2;
        a[i * 2 ] = n - (i - 1) * 2;
        a[n - (i - 1) * 2] = n - (i - 1) * 2 - 1;
        a[n - (i - 1) * 2 - 1] = i * 2 - 1;
    }
    if (n & 1) a[n / 2 + 1] = n / 2 + 1;
    for (i = 1; i <= n; i++) printf("%d ", a[i]);

}