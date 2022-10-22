#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn], l[maxn];
map<int, int> q;

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1;i <= n * 2; ++i) scanf("%d", &a[i]);
        q.clear();
        q[0] = 0;
        for(int i = 1;i <= n * 2; ++i) {
            if(a[i] == 1) l[i] = 1;
            else l[i] = -1;
            l[i] += l[i - 1];
            if(i <= n) q[l[i]] = max(q[l[i]], i);
        }
        int ans = n * 2;
        for(int i = n;i <= n * 2; ++i) {
            int d = l[n * 2] - l[i];
            if(q.find(-d) != q.end()) {
                ans = min(ans, i - n + n - q[-d]);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}