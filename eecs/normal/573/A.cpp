#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while (!(a[i] % 2)) a[i] /= 2;
        while (!(a[i] % 3)) a[i] /= 3;
        V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    puts(V[0] == V.back() ? "Yes" : "No");
    return 0;
}