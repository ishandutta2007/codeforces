// orz KyuushuKyuuhai
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 405;
ll n;struct Ans {int x1,y1,x2,y2;} ans[N];
int a[30];
int main ()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int m = 0,kk = 2,len = 2;while (n) a[++m] = n % 6,n /= 6;
    ans[1] = {1,2,2,2};ans[2] = {2,1,2,2};
    for (int i = m;i > 0;--i)
    {
        if (a[i] <= 2) ans[++kk] = {len - 1,len + 1,len,len + 1};
        if (a[i] % 3 == 0) ans[++kk] = {len - 1,len + 2,len,len + 2};
        ans[++kk] = {len + 1,len - 1,len + 1,len};
        if (a[i] % 3 != 2) {ans[++kk] = {len + 2,len - 1,len + 2,len};}
        len += 2;if (i == 1) continue;
        ans[++kk] = {len - 2,len,len - 2,len + 1};
        ans[++kk] = {len - 1,len,len - 1,len + 1};
        ans[++kk] = {len - 2,len + 2,len - 1,len + 2};
        ans[++kk] = {len,len - 2,len + 1,len - 2};
        ans[++kk] = {len,len - 1,len + 1,len - 1};
        ans[++kk] = {len + 2,len - 2,len + 2,len - 1};
        if (len <= 4) continue;
        ans[++kk] = {len - 4,len + 1,len - 3,len + 1};ans[++kk] = {len + 1,len - 4,len + 1,len - 3};
    }
    cout << len << ' ' << len << endl << kk << endl;
    for (int i = 1;i <= kk;i++)
        cout << ans[i].x1 << ' ' << ans[i].y1 << ' ' << ans[i].x2 << ' ' << ans[i].y2 << endl; 
    return 0;
}