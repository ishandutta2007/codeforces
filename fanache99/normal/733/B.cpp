#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100000;

int left[1 + MAXN], right[1 + MAXN];

int Abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    int answer, which = 0, sumLeft = 0, sumRight = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &left[i], &right[i]);
        sumLeft += left[i];
        sumRight += right[i];
    }
    answer = Abs(sumLeft - sumRight);
    for (int i = 1; i <= n; i++) {
        sumLeft = sumLeft - left[i] + right[i];
        sumRight = sumRight - right[i] + left[i];
        if (Abs(sumLeft - sumRight) > answer) {
            answer = Abs(sumLeft - sumRight);
            which = i;
        }
        sumLeft = sumLeft - right[i] + left[i];
        sumRight = sumRight - left[i] + right[i];
    }
    printf("%d\n", which);
    return 0;
}