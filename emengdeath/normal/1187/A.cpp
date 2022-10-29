#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;
int n , a, b;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &a, &b);
        printf("%d\n", max(a - (a + b - n), b- (a + b - n)) + 1);
    }
    return 0;
}