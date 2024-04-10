#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int n, m, x;
int main(){
    scanf("%d%d", &n, &m);
    if (m < 3 ||(m == 3 && n > 4)){
        printf("-1\n");
        return 0;
    }
    for (x = 1; x <= m; x++)
        printf("%d %d\n", x, x * x + 100000);
    for (x = 1; x <= n - m; x++)
        printf("%d %d\n", x, - x * x - 100000);

}