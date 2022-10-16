#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

char s[1 + MAXN];

int Difference(int a, int b) {
    if (a < b)
        return min(b - a, a + 26 - b);
    else
        return min(a - b, 26 - a + b);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    s[0] = 'a';
    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer += Difference(s[i - 1] - 'a' + 1, s[i] - 'a' + 1);
    printf("%d\n", answer);
    return 0;
}