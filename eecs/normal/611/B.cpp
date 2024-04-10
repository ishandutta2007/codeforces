#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 61; i++) {
        for (int j = 0; j < i - 1; j++) {
            long long c = (1LL << i) - 1 - (1LL << j);
            if (c >= a && c <= b) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}