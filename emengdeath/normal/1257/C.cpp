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
const int N = 2e5 + 10;
int T;
int n;
int a[N];
int ans;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        ans = -1;
        for (int i = 1; i <= n; i ++)
            a[i] = 0;
        for (int i=  1; i <= n ; i++) {
            int x;
            scanf("%d", &x);
            if (a[x]) {
                if (ans ==-1 || ans > i - a[x] + 1)
                    ans = i - a[x] + 1;
                a[x] =i;
            }else
                a[x] = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}