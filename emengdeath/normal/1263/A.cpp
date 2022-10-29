#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int T;
int r, g, b;
int main() {
    scanf("%d", &T);
    while (T --){
        scanf("%d %d %d", &r, &g, &b);
        if (g > b && g > r) swap(g, r);
        if (b > g && b > r) swap(b, r);
        if (r >= g + b) {
            printf("%d\n", g + b);
        }else {
            printf("%d\n", (g + b + r) / 2);
        }
    }
    return 0;
}