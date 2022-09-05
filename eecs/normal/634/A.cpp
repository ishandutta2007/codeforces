#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, a[maxn], b[maxn], mp[maxn];

int main() {
    scanf("%d", &n);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i]) V.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) if (b[i] == V[0]) {
        vector<int> V2;
        for (int j = i, k = 1; k <= n; k++, j = j % n + 1) {
            if (b[j]) V2.push_back(b[j]);
        }
        for (int j = 0; j < V.size(); j++) {
            if (V[j] ^ V2[j]) puts("NO"), exit(0);
        }
        puts("YES");
        exit(0);
    }
    puts("NO");
    return 0;
}