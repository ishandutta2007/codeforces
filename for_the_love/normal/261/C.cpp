#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long f[1000][1000], g[1000][1000], n, t, m, cnt, ans, i, num;
long long check(long long x){
    long long ret = 0;
    while (x % 2 == 0){
        x = x / 2;
        ret++;
    }
    if (x != 1) return -1;
    return ret;
}
int main(){
    cin >> n >> t;
    t = check(t);
    if (t == -1){
        cout << 0 << endl;
        return 0;
    }
    f[0][0] = 1;
    g[0][0] = 1;
    f[1][0] = 1; f[1][1] = 1;
    g[1][0] = 1; g[1][1] = 1;
    m = 2; num = 2; cnt = 1;
    while (num + m + m <= n){
        m = m + m;
        num += m;
        cnt++;
        for (i = 1; i <= cnt; i++) f[cnt][i] = f[cnt - 1][i] + f[cnt - 1][i - 1];
        f[cnt][0] = 1;
        for (i = 0; i <= cnt; i++) g[cnt][i] = g[cnt - 1][i] + f[cnt][i];
    }
    if (n >= num){
        ans = g[cnt][t];
        n -= num;
    }
    while (n != 0)
    if (m > n){
        m = m / 2;
        cnt--;
    }
    else{
        ans += f[cnt][t];
        n -= m;
        t--;
    }
    cout << ans << endl;
}