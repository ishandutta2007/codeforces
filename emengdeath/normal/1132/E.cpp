#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
long long w[8];
long long W;
long long ans = 0;
void dfs(int x, long long v) {
    if (x == 0) {
        ans = max(ans, W - v);
        return;
    }
    long long y = min(w[x - 1], v / x);
    for (int i = 0; y - i >= 0 && i <= x; i ++) {
        dfs(x - 1, v - (y - i) * x);
    }
}
int main() {
    cin>>W;
    for (int i = 1; i <=8; i ++)
        cin>>w[i - 1];
    long long tmp = W;
    dfs(8, W);
    cout << ans;
    return 0;
}