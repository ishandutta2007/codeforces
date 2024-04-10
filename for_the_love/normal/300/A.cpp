#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, a[1000];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    printf("%d %d\n", 1, a[1]);
    if (a[n] == 0){
        printf("%d %d %d\n", 2, a[2], a[3]);
        printf("%d", n - 3);
        for (i = 4; i <= n; i++) printf(" %d", a[i]);
        return 0;
    }
    printf("%d %d\n", 1, a[n]);
    printf("%d", n - 2);
    for (i = 2; i <= n - 1; i++) printf(" %d", a[i]);
    puts("");
}