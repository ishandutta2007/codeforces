#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, h[maxn], ok[maxn];
deque<int> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    auto chk = [&](int x) {
        for (int i = 1; i <= n; i++) {
            if (i >= x && i + x - 1 <= n) ok[i] = h[i] >= x;
            else ok[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            while (!Q.empty() && h[Q.back()] - Q.back() > h[i] - i) Q.pop_back();
            Q.push_back(i);
            while (!Q.empty() && Q.front() <= i - x + 1) Q.pop_front();
            ok[i + 1] &= h[Q.front()] - Q.front() >= (x - (i + 1));
        }
        Q.clear();
        for (int i = n; i; i--) {
            while (!Q.empty() && h[Q.back()] + Q.back() > h[i] + i) Q.pop_back();
            Q.push_back(i);
            while (!Q.empty() && Q.front() >= i + x - 1) Q.pop_front();
            ok[i - 1] &= h[Q.front()] + Q.front() >= (x + (i - 1));
        }
        return accumulate(ok + 1, ok + n + 1, 0);
    };
    int l = 2, r = (n + 1) / 2, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}