#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN];

int BinarySearch(int left, int right, int value) {
    int answer = left - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (v[middle] < value) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == v[i - 1])
            continue;
        int limit = i - 1;
        long long current = 0;
        for (int j = 2 * v[i]; j <= 2 * MAXN; j += v[i]) {
            int next = BinarySearch(limit + 1, n, j);
            current = current + 1LL * (j - v[i]) * (next - limit);
            limit = next;
        }
        answer = max(answer, current);
    }
    printf("%I64d\n", answer);
    return 0;
}