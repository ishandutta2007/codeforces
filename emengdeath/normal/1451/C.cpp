#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[26], b[26];
int n, k;
int T;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &k);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n;i ++) {
            char c;
            scanf(" %c", &c);
            a[c - 'a'] ++;
        }
        for (int i = 1; i <= n;i ++) {
            char c;
            scanf(" %c", &c);
            b[c - 'a'] ++;
        }
        bool sig = 1;
        for (int i = 0; i < 25 && sig; i ++) {
            if (a[i] < b[i]) {
                sig = 0;
                break;
            }
            if (a[i] > b[i]) {
                int cnt = (a[i] - b[i]) / k * k;
                a[i] -= cnt;
                a[i + 1] += cnt;
                cnt = a[i] - b[i];
                if (cnt) {
                    sig = 0;
                }
            }
        }
        sig ? puts("Yes"):puts("No");
    }
    return 0;
}