#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
bool check(char c) {
    return c >= 'a' && c <= 'z';
}
int a[27][2];
bool bz[27];
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(a, 0, sizeof(a));
        memset(bz, 0, sizeof(bz));
        char c;
        while (!check(c = getchar()));
        int s = c - 'a' + 1;
        c = getchar();
        bool sig = 1;
        int st = s;
        bz[s] = 1;
        while (check(c)) {
            c -= 'a' - 1;
            if (c!=s) {
                if (a[s][0] != c && a[s][1] != c) {
                    if (bz[c] && c != a[s][0] && c != a[s][1]) {
                        sig = 0;
                    }
                    if (!a[s][0] && !a[c][1])
                        a[s][0] = c, a[c][1] = s;
                    else {
                        if (!a[s][1] && !a[c][0])
                            a[s][1] = c, a[c][0] = s;
                        else
                            sig = 0;
                    }
                }
            }
            bz[c] = 1;
            s = c;
            c = getchar();
        }
        if (!sig) {
            puts("NO");
            continue;
        }
        puts("YES");
        while (a[st][0]) st = a[st][0];
        printf("%c", st - 1 + 'a');
        while (a[st][1]) {
            st = a[st][1];
            printf("%c", st - 1 + 'a');
        }
        for (int i = 1; i <= 26; i ++)
            if (!bz[i])
                printf("%c", i - 1 +'a');
        printf("\n");
    }
    return 0;
}