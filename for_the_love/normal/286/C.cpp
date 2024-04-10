#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, i, a[1000005], b[1000005], z[1000005], top;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        a[b[i]] = - a[b[i]];
    }
    for (i = n; i >= 1; i--)
    if (a[i] > 0){
        if (top && z[top] == a[i]) top--;
        else{
            z[++top] = a[i];
            a[i] = -a[i];
        }
    }else z[++top] = -a[i];
    if (top) printf("NO\n"); else{
        printf("YES\n");
        for (i = 1; i <= n; i++) printf("%d ", a[i]);
    }
}