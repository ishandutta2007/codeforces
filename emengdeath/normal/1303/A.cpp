#include <algorithm>
#include <cstdio>
using namespace std;
bool check(char c) {
    return c == '0' || c == '1';
}
char s[1000000];
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        char c;
        while (!check(c = getchar()));
        int tot = 0;
        bool haveone = 0;
        while (check(c)) {
            s[++tot] = c - '0';
            haveone |= s[tot];
            c = getchar();
        }
        if (!haveone) {
            printf("0\n");
            continue;
        }
        int l = 1, r = tot;
        while (!s[l])l ++;
        while (!s[r]) r --;
        int ans = 0;
        for (int i = l; i <= r; i ++)
            ans += !s[i];
        printf("%d\n", ans);
    }
    return 0;
}