#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int T;
int D, k;
pair<int, int> d[100001];
int main() {
    scanf("%d", &T);

    while (T --) {
        scanf("%d %d", &D, &k);
        int ans = 0;
        for (int i = 0; i <= D; i ++) {
            int j = sqrt(1ll * D * D - 1ll * i * i);
            ans = max(ans, j / k + i / k);
        }
        (ans & 1)? puts("Ashish"):puts("Utkarsh");
    }
    return 0;
}