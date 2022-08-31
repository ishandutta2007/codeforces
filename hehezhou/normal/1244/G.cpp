#include <bits/stdc++.h>
using namespace std;
int ans[1000010], n;
long long k;
int main() {
    cin >> n >> k;
    if(1ll * n * (n + 1) / 2 > k) return puts("-1"), 0;
    long long _max = 0;
    for(int i = 1; i <= n; i++) _max += max(i, n - i + 1);
    if(_max < k) k = _max;
    cout << k << endl;
    for(int i = 1; i <= n; i++) ans[i] = i, printf("%d%c", i, " \n"[i == n]);
    k -= 1ll * n * (n + 1) / 2;
    for(int i = 1; ; i++) {
        int now = n - 2 * i + 1;
        if(k <= now || k == 0) {
            swap(ans[i], ans[i + k]);
            for(int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
            return 0;
        }
        else k -= now, swap(ans[i], ans[n - i + 1]);
    }
}