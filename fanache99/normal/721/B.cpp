#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

char s[1 + MAXN];
int length[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d\n", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        length[strlen(s + 1)]++;
    }
    scanf("%s", s + 1);
    int x = strlen(s + 1);
    int answer = 0, tries = 0;
    for (int i = 1; i < x; i++)
        for (int j = 1; j <= length[i]; j++) {
            answer++;
            tries++;
            if (tries == k) {
                tries = 0;
                answer += 5;
            }
        }
    printf("%d ", answer + 1);
    for (int i = 1; i < length[x]; i++) {
        answer++;
        tries++;
        if (tries == k) {
            tries = 0;
            answer += 5;
        }
    }
    printf("%d ", answer + 1);
    return 0;
}