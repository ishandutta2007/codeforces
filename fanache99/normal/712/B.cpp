#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100000;

char s[1 + MAXN];

int Abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int left = 0, right = 0, up = 0, down = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R')
            right++;
        if (s[i] == 'D')
            down++;
        if (s[i] == 'U')
            up++;
        if (s[i] == 'L')
            left++;
    }
    if (Abs(right - left) % 2 + Abs(up - down) % 2 == 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", Abs(right - left) / 2 + Abs(down - up) / 2 + (Abs(right - left) % 2 + Abs(right - left) % 2) / 2);
    return 0;
}