#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>
#include <queue>

const int N = 200000;

struct Problem
{
    int a, t, id;
};

bool operator < (const Problem& a, const Problem& b)
{
    return a.t < b.t;
}

Problem p[N];

bool by_a(const Problem& a, const Problem& b)
{
    return a.a < b.a;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &p[i].a, &p[i].t);
            p[i].id = i;
        }
        std::sort(p, p + n, by_a);
        std::priority_queue<Problem> solved;
        int sum = 0;
        for (int k = n, j = n - 1; k >= 0; -- k) {
            while (j >= 0 && p[j].a >= k) {
                sum += p[j].t;
                solved.push(p[j --]);
            }
            while ((int)solved.size() > k) {
                sum -= solved.top().t;
                solved.pop();
            }
            if ((int)solved.size() == k && sum <= m) {
                printf("%d\n%d\n", k, k);
                while (!solved.empty()) {
                    printf("%d ", solved.top().id + 1);
                    solved.pop();
                }
                puts("");
                break;
            }
        }
    }
}