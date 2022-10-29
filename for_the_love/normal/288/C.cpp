#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x, m, y, i, a[1000005], ans[1000005];
int main(){
    scanf("%d", &n);
    int t = n;
    cout << ((long long)n) * (n + 1) << endl;
    while (n > 0){
        x = n;
        m = 0;
        while (x){
            a[m++] = x % 2;
            x = x / 2;
        }
        y = 0;
        for (i = 0; i < m; i++) y = y + (1 << i) * (1 - a[i]);
        for (i = y; i <= n; i++) ans[i] = y + (n - i);
        n = y - 1;
    }
    for (i = 0; i <= t; i++) cout << ans[i] << " ";
    cout << endl;
}