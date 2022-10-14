#include <bits/stdc++.h>

using LL = long long;

struct Point
{
    explicit Point(int x, int y)
        : x(x), y(y) {}

    int quad() const
    {
        return y == 0 ? x > 0 : y > 0;
    }

    int x, y;
};

LL det(const Point& a, const Point& b)
{
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

Point operator - (const Point& a, const Point& b)
{
    return Point { a.x - b.x, a.y - b.y };
}

const int N = 2000;

int n, pos[N], ord[N], ans[3];
LL s;
std::vector<Point> p;

bool by_y(int i, int j)
{
    if (p[i].y != p[j].y) {
        return p[i].y < p[j].y;
    }
    return p[i].x < p[j].x;
}

bool by_ang(const std::pair<int, int>& u, const std::pair<int, int>& v)
{
    auto a = p[u.second] - p[u.first];
    auto b = p[v.second] - p[v.first];
    if (a.quad() != b.quad()) {
        return a.quad() < b.quad();
    }
    return det(a, b) > 0;
}

bool solve()
{
    std::vector<std::pair<int, int>> events;
    for (int i = 0; i < n; ++ i) {
        ord[i] = i;
        for (int j = 0; j < n; ++ j) {
            if (i != j) {
                events.emplace_back(i, j);
            }
        }
    }
    std::sort(events.begin(), events.end(), by_ang);
    std::sort(ord, ord + n, by_y);
    for (int i = 0; i < n; ++ i) {
        pos[ord[i]] = i;
    }
    for (auto&& pr : events) {
        int i = pr.first;
        int j = pr.second;
        int it = std::lower_bound(ord + pos[i], ord + n, s, [i, j](int k, LL s) {
            return det(p[k] - p[i], p[j] - p[i]) < 2 * s;
        }) - ord;
        if (it != n) {
            int k = ord[it];
            if (det(p[k] - p[i], p[j] - p[i]) == 2 * s) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = k;
                return true;
            }
        }
        std::swap(ord[pos[i]], ord[pos[j]]);
        std::swap(pos[i], pos[j]);
    }
    return false;
}

int main()
{
    std::cin >> n >> s;
    for (int i = 0, x, y; i < n; ++ i) {
        std::cin >> x >> y;
        p.emplace_back(x, y);
    }
    if (solve()) {
        puts("Yes");
        for (int i = 0; i < 3; ++ i) {
            printf("%d %d\n", p[ans[i]].x, p[ans[i]].y);
        }
    } else {
        puts("No");
    }
}