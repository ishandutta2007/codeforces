#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 1000000;
const int B = 1000;

int x[N], y[N];
std::vector<int> buckets[B];

bool by_y(int i, int j) {
    return y[i] < y[j];
}

bool by_rev_y(int i, int j) {
    return y[i] > y[j];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", x + i, y + i);
        buckets[std::min(x[i] / B, B - 1)].push_back(i);
    }
    for (int i = 0; i < B; ++ i) {
        if (i & 1) {
            std::sort(buckets[i].begin(), buckets[i].end(), by_y);
        } else {
            std::sort(buckets[i].begin(), buckets[i].end(), by_rev_y);
        }
    }
    for (int i = 0; i < B; ++ i) {
        for (int x : buckets[i]) {
            printf("%d ", x + 1);
        }
    }
    puts("");
    return 0;
}