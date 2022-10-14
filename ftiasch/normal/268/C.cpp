#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 101;

int n, m, p[N];
bool swaped;

int square(int x) {
    return x * x;
}

bool is_square[20001];
bool used[N];

int main() {
    memset(is_square, 0, sizeof(is_square));
    for (int i = 0; i * i <= 20000; ++ i) {
        is_square[i * i] = true;
    }
    scanf("%d%d", &n, &m);
    if (n > m) {
        swaped = true;
        std::swap(n, m);
    } else {
        swaped = false;
    }
    while (true) {
        memset(used, 0, sizeof(used));
        bool fail = false;
        for (int i = 0; i <= n && !fail; ++ i) {
            std::vector <int> choices;
            for (int j = 0; j <= m; ++ j) {
                if (!used[j] && (i || j)) {
                    choices.push_back(j);
                } 
            }
            std::random_shuffle(choices.begin(), choices.end());
            bool found = false;
            for (int j = 0; j < (int)choices.size() && !found; ++ j) {
                p[i] = choices[j];
                bool valid = true;
                for (int k = 0; k < i; ++ k) {
                    valid &= !is_square[square(i - k) + square(p[i] - p[k])];
                }
                if (valid) {
                    used[p[i]] = true;
                    found = true;
                }
            }
            if (!found) {
                fail = true;
            }
        }
        if (!fail) {
            break;
        }
    }
    printf("%d\n", n + 1);
    for (int i = 0; i <= n; ++ i) {
        if (swaped) {
            printf("%d %d\n", p[i], i);
        } else {
            printf("%d %d\n", i, p[i]);
        }
    }
    return 0;
}