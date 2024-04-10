#include <cstdio>
#include <cstring>
#include <deque>
#include <utility>
#include <algorithm>

const int N = 100000;

int n, a[N], answer[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::deque <std::pair <int, int> > deque;
    for (int i = n - 1; i >= 0; -- i) {
        std::deque <std::pair <int, int> > :: iterator iter = std::lower_bound(deque.begin(), deque.end(), std::make_pair(a[i], -1));
        if (iter == deque.begin()) {
            answer[i] = -1;
        } else {
            answer[i] = (iter - 1)->second - i - 1;
        }
        if (deque.empty() || a[i] < deque.front().first) {
            deque.push_front(std::make_pair(a[i], i));
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", answer[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}