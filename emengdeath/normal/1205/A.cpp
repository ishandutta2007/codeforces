#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
int n;
int a[1000000];
int main() {
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 1; i <= n; i ++)
        {
            if (i & 1)
                a[i] = i * 2 - 1, a[n+i] = i * 2;
            else
                a[i] = i * 2, a[n + i] = i * 2 - 1;
        }
        printf("YES\n");
        for (int i =  1; i <= n + n; i ++)
            printf("%d ",a[i]);
    } else
        printf("NO\n");
    return 0;
}