#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;

int main(){
    int n, x;
    scanf("%d", &n);

    int last = 0;
    LL ans = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        ans += abs(x - last);
        last = x;
    }
    printf("%I64d\n", ans);
}