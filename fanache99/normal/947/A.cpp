#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1000000;

int low[1 + MAXN];

void Precompute(int n) {
    for (int i = 2; i <= n; i++)
        if (!low[i]) {
            low[i] = i;
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    if (!low[j])
                        low[j] = i;
        }

}

int Low(int n) {
    int answer = n, initial = n;
    if (low[n] == n)
        return n;
    while (n != 1) {
        int base = low[n];
        answer = min(answer, initial - base + 1);
        while (low[n] == base)
            n /= base;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    Precompute(n);
    int answer = n;
    for (int i = Low(n); i <= n; i++)
        answer = min(answer, Low(i));
    printf("%d\n", answer);
    return 0;
}