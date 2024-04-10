#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
priority_queue<pair<int, int> > q;
int n;
int cnt[N];
void change(int x, int y) {
    cnt[x] += y;
    if (cnt[x] >= 2)
        q.push({cnt[x], x});
}
void upd() {
    while (q.size() && q.top().first != cnt[q.top().second]) q.pop();
}
int main() {
    scanf("%d", &n);
    while (n --) {
        int x;
        scanf("%d", &x);
        change(x, 1);
    }
    scanf("%d", &n);
    while (n --) {
        char c;
        int x;
        scanf(" %c %d", &c, &x);
        change(x, (c == '+') * 2 - 1);
        upd();
        if (q.empty() || q.top().first < 4) {
            puts("NO");
            continue;
        }
        auto u = q.top();
        change(u.second, -4);
        upd();
        if (q.empty()) {
            change(u.second, 4);
            puts("NO");
            continue;
        }
        if (q.top().first == 4) {
            puts("YES");
            change(u.second, 4);
            continue;
        }
        auto v = q.top();
        change(v.second, -2);
        upd();
        if (q.empty()) {
            change(v.second, 2);
            change(u.second, 4);
            puts("NO");
            continue;
        }
        puts("YES");
        change(v.second, 2);
        change(u.second, 4);
    }
    return 0;
}