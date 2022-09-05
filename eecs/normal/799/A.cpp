#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    puts((n - 1) / k * t > d ? "YES" : "NO");
    return 0;
}