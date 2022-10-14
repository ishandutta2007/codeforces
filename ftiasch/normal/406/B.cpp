#include <cstdio>
#include <cstring>
#include <vector>

const int N = 500000;
const int M = 1000000;

int n, a[N];
bool has[M + 1];

int main() {
    scanf("%d", &n);
    memset(has, 0, sizeof(has));
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        has[a[i]] = true;
    }
    std::vector <int> result;
    int pair = 0;
    for (int i = 1; i <= M; ++ i) {
        if (has[i]) {
            if (has[M - (i - 1)]) {
                pair ++;
            } else {
                result.push_back(M - (i - 1));
            }
        }
    }
    pair /= 2;
    for (int i = 1; i <= M && pair; ++ i) {
        if (!has[i] && !has[M - (i - 1)]) {
            pair --;
            result.push_back(i);
            result.push_back(M - (i - 1));
        }
    }
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); ++ i) {
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);
    }
    return 0;
}