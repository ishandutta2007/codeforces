#include <bits/stdc++.h>
using namespace std;
struct node {
    int i, d;
} t[100010];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &t[i].d), t[i].i = i;
    sort(t + 1, t + 1 + n, [](node a, node b) {
        return a.d > b.d;
    });
    vector<int> v;
    for(int i = 1; i < n; i++) printf("%d %d\n", t[i + 1].i * 2, t[i].i * 2), v.push_back(t[i].i * 2);
    v.push_back(t[n].i * 2);
    for(int i = 1; i <= n; i++) {
        int d = t[i].d - 2 + i;
        printf("%d %d\n", v[d], 2 * t[i].i - 1);
        if(d == v.size() - 1) v.push_back(2 * t[i].i - 1);
    }
    return 0;
}