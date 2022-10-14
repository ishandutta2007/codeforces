#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    puts(std::accumulate(a.begin(), a.end(), 0) + (n - 1) == m ? "YES" : "NO");
}