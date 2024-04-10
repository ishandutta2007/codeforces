#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 111111;

int n, a[N], cnt[N];

int main() {
    scanf("%d", &n);
    int minA = INT_MAX;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        minA = min(minA, a[i]);
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++ i) {
        a[i] -= minA;
        if (a[i] >= N) {
            puts("NO");
            return 0;
        }
        cnt[a[i]] ++;
    }
    if (n & 1) {
        puts("NO");
        return 0;
    }
    int tmp = 0;
    cnt[0] --;
    for (int i = 1; i < n; ++ i) {
        if (tmp + 1 < N && cnt[tmp + 1]) {
            tmp ++;
            cnt[tmp] --;
        } else if (tmp - 1 >= 0 && cnt[tmp - 1]) {
            tmp --;
            cnt[tmp] --;
        } else {
            puts("NO");
            return 0;
        }
    }
    if (tmp != 1) {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}