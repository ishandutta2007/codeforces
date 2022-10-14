#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <functional>
#include <algorithm>

int n;
std::vector <int> books[2];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int t, w;
        scanf("%d%d", &t, &w);
        books[-- t].push_back(w);
    }
    for (int i = 0; i < 2; ++ i) {
        std::sort(books[i].begin(), books[i].end(), std::greater <int>());
    }
    int answer = INT_MAX;
    for (int i = 0; i <= (int)books[0].size(); ++ i) {
        for (int j = 0; j <= (int)books[1].size(); ++ j) {
            int total = 0;
            for (int k = i; k < (int)books[0].size(); ++ k) {
                total += books[0][k];
            }
            for (int k = j; k < (int)books[1].size(); ++ k) {
                total += books[1][k];
            }
            if (total <= i + 2 * j) {
                answer = std::min(answer, i + 2 * j);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}