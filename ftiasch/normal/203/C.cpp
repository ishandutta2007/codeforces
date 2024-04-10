#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

const int N = 100000;

int n, d, a, b;
std::pair <int, int> clients[N];


int main() {
    scanf("%d%d%d%d", &n, &d, &a, &b);
    for (int i = 0; i < n; ++ i) {
        int x, y;
        scanf("%d%d", &x, &y);
        clients[i] = std::make_pair(x * a + y * b, i);
    }
    std::sort(clients, clients + n);
    int result = 0;
    while (result < n && clients[result].first <= d) {
        d -= clients[result ++].first;
    }
    printf("%d\n", result);
    for (int i = 0; i < result; ++ i) {
        printf("%d%c", clients[i].second + 1, " \n"[i == result - 1]);
    }
    return 0;
}