#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
char s[500010];
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    if (k == 2) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i ++) {
            int x = i & 1;
            if (x & s[i] != 'A')   cnt1 ++;
            if (!x & s[i] != 'B')  cnt1 ++;
        }
        for (int i = 1; i <= n; i ++) {
            int x = i & 1;
            if (x & s[i] != 'B')   cnt2 ++;
            if (!x & s[i] != 'A')  cnt2 ++;
        }
        if (cnt1 <= cnt2) {
            printf("%d\n", cnt1);
            for (int i = 1; i <= n; i ++) {
                int x = i & 1;
                printf("%c", x ? 'A' : 'B');
            }
        }
        else  {
            printf("%d\n", cnt2);
            for (int i = 1; i <= n; i ++) {
                int x = i & 1;
                printf("%c", x ? 'B' : 'A');
            }
        }
        puts("");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) if (s[i] == s[i - 1]) {
        for (int j = 1; j <= k; j ++) {
            if (j - 1 + 'A' != s[i - 1] && j - 1 + 'A' != s[i + 1]) {
                s[i] = j - 1 + 'A';
                cnt ++;
                break;
              //  printf("i = %d\n", i);
            }
        }
    }
    printf("%d\n%s\n", cnt, s + 1);
    return 0;

}