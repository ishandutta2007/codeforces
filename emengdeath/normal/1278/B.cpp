#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a, b;
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &a, &b);
        if (a > b)swap(a, b);
        int ans = 0;
        while (a < b || ((a + b) & 1)) {
            a += (++ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}