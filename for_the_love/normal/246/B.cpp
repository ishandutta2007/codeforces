#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp, i, sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &tmp);
        sum += tmp;
    }
    if (sum % n == 0) printf("%d\n", n); else printf("%d\n", n-1);
    return 0;

}