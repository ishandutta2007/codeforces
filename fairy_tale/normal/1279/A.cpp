#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while(t--) {
        int r, g, b;
        cin >> r >> g >> b;
        if(g < b) swap(g, b);
        if(r < g) swap(r, g);
        if(r <= g + b + 1)puts("Yes");
        else puts("No");
    }
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}