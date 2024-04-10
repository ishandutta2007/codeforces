#include <cstdio>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <iostream>
#include <algorithm>

int n;
std::deque <std::pair <int, long long> > stack;

int main() {
    scanf("%d", &n);
    for (int i = 0, a; i < n; ++ i) {
        scanf("%d", &a);
        stack.push_back(std::make_pair(i, a));
    }
    int m;
    scanf("%d", &m);
    while (m --) {
        int w, h;
        scanf("%d%d", &w, &h);
        long long ret = (std::lower_bound(stack.begin(), stack.end(), std::make_pair(w, -1LL)) - 1)->second;
        while (!stack.empty() && ret + h >= stack.front().second) {
            stack.pop_front();
        }
        stack.push_front(std::make_pair(0, ret + h));
        std::cout << ret << std::endl;
    }
    return 0;
}