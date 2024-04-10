#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN], start[1 + MAXN];
map<int, bool> seen;
int numbers[2], pointer[2];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    pointer[0] = 2;
    pointer[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        numbers[v[i] % 2]++;
        start[i] = v[i];
    }
    for (int i = 1; i <= n; i++) {
        if (seen[v[i]] == true) {
            int which = v[i] % 2;
            if (numbers[v[i] % 2] > numbers[1 - v[i] % 2])
                which = 1 - v[i] % 2;
            while (pointer[which] <= m && seen[pointer[which]] == true)
                pointer[which] += 2;
            if (pointer[which] > m) {
                printf("-1\n");
                return 0;
            }
            numbers[v[i] % 2]--;
            v[i] = pointer[which];
            numbers[v[i] % 2]++;
            pointer[which] += 2;
        }
        seen[v[i]] = true;
    }
    for (int i = 1; i <= n; i++)
        if (numbers[v[i] % 2] > numbers[1 - v[i] % 2]) {
            int which = 1 - v[i] % 2;
            while (pointer[which] <= m && seen[pointer[which]] == true)
                pointer[which] += 2;
            if (pointer[which] > m) {
                printf("-1\n");
                return 0;
            }
            numbers[v[i] % 2]--;
            v[i] = pointer[which];
            numbers[v[i] % 2]++;
            pointer[which] += 2;
        }
    if (numbers[0] != numbers[1]) {
        printf("-1\n");
        return 0;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (start[i] != v[i])
            answer++;
    printf("%d\n", answer);
    for (int i = 1; i <= n; i++)
        printf("%d ", v[i]);
    return 0;
}