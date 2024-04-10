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
        scanf("%d %d", &a, &b);
        if (a >= b) printf("YES\n");
        else {
            if (a > 3) printf("YES\n");
            else
                if (a == 1) {
                    printf("NO\n");
                } else
                    if (b <= 3){
                        printf("YES\n");
                    } else printf("NO\n");
        }
    }
    return 0;
}