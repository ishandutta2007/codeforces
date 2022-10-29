#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long m = 360360;
long long f[360361], a, b, k, ans;
long long Calc(long long st, long long ed){
    long long i, j;
    //cout << st << " " << ed << endl;
    memset(f, 0x7f, sizeof(f));
    f[m] = 0;
    for (i = st; i >= ed; i--){
        if (m - st + i - 1 >= 0) f[m - st + i - 1] = min(f[m - st + i - 1], f[m - st + i] + 1);
        for (j = 2; j <= k; j++)
        if (m - st + i / j * j >= 0)
            f[m - st + i / j * j] = min(f[m - st + i / j * j], f[m - st + i] + 1);
    }
    //cout << f[m - st + ed] << endl;
    return f[m - st + ed];
}

int main(){
    cin >> a >> b >> k;
    if (a / m == b / m){
        cout << Calc(a, b) << endl;
        return 0;
    }
    ans = Calc(a, a / m * m);
    if (b % m != 0) cout << ans + Calc((b / m + 1) * m, b) + Calc(m, 0) * (a / m - b / m - 1) << endl;
    else cout << ans + Calc((b / m + 1) * m, b) + Calc(m, 0) * (a / m - b / m) << endl;
}