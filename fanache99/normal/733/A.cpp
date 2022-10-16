#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100;

char s[1 + MAXN];

bool Vowel(char ch) {
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y')
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1), last = 0, answer = 1;
    for (int i = 1; i <= n; i++)
        if (Vowel(s[i])) {
            answer = max(answer, i - last);
            last = i;
        }
    answer = max(answer, n + 1 - last);
    printf("%d\n", answer);
    return 0;
}