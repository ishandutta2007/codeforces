#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <algorithm>

#define SIZE(v) (int)(v).size()

const int N = 100000;
const long long INF = 2000000000000000000LL;

int n, m, p, d[N], w[N];
long long minimum[2][N + 1];

struct Line {
    long long a, b;

    Line(long long a, long long b) : a(a), b(b) {}

    long long at(long long x) const {
        return a * x + b;
    }
};

bool check(const Line &u, const Line &v, const Line &w) {
    return (double)(u.b - v.b) / (v.a - u.a) < (double)(v.b - w.b) / (w.a - v.a);
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    d[0] = 0;
    for (int i = 1; i < n; ++ i) {
        scanf("%d", d + i);
        d[i] += d[i - 1];
    }
    for (int i = 0; i < m; ++ i) {
        int h, t;
        scanf("%d%d", &h, &t);
        h --;
        w[i] = t - d[h];
    }
    std::sort(w, w + m, std::greater <int>());
    minimum[0][m] = 0;
    std::fill(minimum[0], minimum[0] + m, INF);
    for (int i = 0; i < p; ++ i) {
        std::deque <Line> stack;
        minimum[i + 1 & 1][m] = 0;
        for (int j = m; j >= 0; -- j) {
            if (j < m) {
                long long now_w = w[j];
                while (SIZE(stack) >= 2 && stack[0].at(now_w) > stack[1].at(now_w)) {
                    stack.pop_front();
                }
                minimum[i + 1 & 1][j] = std::min(minimum[i & 1][j], stack[0].at(now_w) - (long long)w[j] * j);
            }
            while (SIZE(stack) >= 2 && !check(stack[SIZE(stack) - 2], stack[SIZE(stack) - 1], Line(j, minimum[i & 1][j]))) {
                stack.pop_back();
            }
            stack.push_back(Line(j, minimum[i & 1][j]));
        }
    }
    long long answer = minimum[p & 1][0];
    for (int i = 0; i < m; ++ i) {
        answer -= w[i];
    }
    std::cout << answer << std::endl;
    return 0;
}