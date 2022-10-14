#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 300000;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    long long answer = 0;
    for (int i = 0; i < n; ++ i) {
        answer += std::abs(a[i] - (i + 1));
    }
    std::cout << answer << std::endl;
    return 0;
}