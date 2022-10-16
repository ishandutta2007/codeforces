#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 500;

int n, a[1 + MAXN], b[1 + MAXN], where[1 + MAXN];

void Erase(int index) {
    for (int i = index; i < n; i++)
        a[i] = a[i + 1];
    a[n] = 0;
    n--;
}

void Eat(int left, int right) {
    int now = left;
    for (int i = left; i <= right; i++)
        if (a[i] > a[now])
            now = i;
    int value = a[now];
    for (int i = left; i <= right; i++)
        if (a[i] == value && ((i != left && a[i] > a[i - 1]) || (i != right && a[i] > a[i + 1]))) {
            now = i;
            break;
        }
    for (int i = 1; i <= right - left; i++)
        if (now < right - i + 1 && a[now] > a[now + 1]) {
            a[now] += a[now + 1];
            printf("%d R\n", now);
            Erase(now + 1);
        }
        else {
            a[now] += a[now - 1];
            printf("%d L\n", now);
            Erase(now - 1);
            now--;
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
        scanf("%d", &b[i]);
    int pointer = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (pointer == k + 1) {
            printf("NO\n");
            return 0;
        }
        if (sum > b[pointer]) {
            printf("NO\n");
            return 0;
        }
        if (sum == b[pointer]) {
            sum = 0;
            where[pointer] = i;
            pointer++;
        }
    }
    if (pointer != k + 1) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= k; i++)
        if (where[i] - where[i - 1] != 1) {
            int first = a[where[i - 1] + 1];
            for (int j = where[i - 1] + 2; j <= where[i]; j++)
                if (a[j] != first) {
                    first = -1;
                    break;
                }
            if (first != -1) {
                printf("NO\n");
                return 0;
            }
        }
    printf("YES\n");
    for (int i = k; i >= 1; i--)
        Eat(where[i - 1] + 1, where[i]);
    return 0;
}