#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long c[100005], ans;
int tmp, cnt, m, n, i, x;
int main(){
    cin >> m;
    cnt = 10000000;
    for (i = 1; i <= m; i++){
        cin >> tmp;
        cnt = min(cnt, tmp);
    }
    cin >> n;
    for (i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + n + 1);
    x = cnt + 2;
    ans = 0;
    for (i = n; i >= 1; i--){
        if (x > 2) ans +=c[i];
        x--;
        if (!x) x = cnt + 2;
    }
    cout << ans << endl;
}