#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, ans;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        ans += (n - i) * i + 1;
    printf("%d\n", ans);

}