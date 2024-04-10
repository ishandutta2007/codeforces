#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, k, m;
int d[100000];
pair<int, int> ask(int * a) {
    printf("?");
    for (int i =0; i < k; i ++)
        printf(" %d", a[i]);
    printf("\n");
    fflush(stdout);
    pair<int, int> u;
    scanf("%d %d", &u.first, &u.second);
    return u;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i ++)
        d[i] = i;
    pair<int, int> u = ask(d + 1);
    int cnt = 0;
    for (int i = 1; i <= k + 1; i ++)
        if (i!= u.first)
            d[++cnt] = i;
    pair<int, int> v = ask(d + 1);
    if (u.second > v.second) swap(u, v);
    vector<int>w;
    for (int i = 1; i <= k + 1; i ++)
        if (i!= u.first && i != v.first){
            w.push_back(i);
        }
    int ans = 1;
    for (auto x:w) {
        cnt = 2;
        d[1] = u.first;
        d[2] = v.first;
        for (auto y:w)
            if (y != x)
                d[++cnt] = y;
        ans += (ask(d + 1).first == v.first);
    }
    printf("! %d\n", ans);
    return 0;
}