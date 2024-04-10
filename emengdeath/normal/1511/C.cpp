#include <algorithm>
#include <cstdio>
using namespace std;
int n, q;
int a[51];
int main() 
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if (!a[x]) a[x] = i;
    }
    while (q --) {
        int x;
        scanf("%d", &x);
        printf("%d\n", a[x]);
        for (int i = 1; i <= 50;  i ++) 
            if (i != x && a[i] < a[x])a[i] ++;

        a[x] = 1;
    }
    return 0;
}