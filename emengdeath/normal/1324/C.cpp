#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int T, n;
char s[1000000];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        n = strlen(s);
        int last = -1;
        int mx = 0;
        s[n] = 'R';
        for (int i = 0; i <= n; i ++)
            if (s[i] == 'R')
                mx = max(mx, i - last), last = i;
        printf("%d\n", mx);
    }
    return 0;
}