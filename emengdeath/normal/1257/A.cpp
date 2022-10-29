#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;
typedef long long ll;
int T;
int n, x, a, b;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %d", &n, &x, &a, &b);
        if (a > b) swap(a, b);
        if (a - 1 >= x) a -=x , x = 0;
        else
            x -= a- 1, a= 1;
        if (n - b >= x) b += x;
        else
            b = n;
        printf("%d\n", b-a);
    }
    return 0;
}