#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int upper = 20000;

typedef long long ll;

int k;
ll n,f[101][upper],a[101];

ll F(int i,ll now)
{
    if (i == k)
        return now;
    if (now == 0)
        return 0;
    if (now < upper && f[i][now] >= 0) return f[i][now];
    ll ret = F(i+1,now) - F(i+1,now/a[i]);
    if (now < upper) f[i][now] = ret;
    return ret;
}

int main()
{
    cin >> n >> k;
    for (int i = 0;i < k;++i)
        cin >> a[i];
    for (int i = 0;i < k;++i)
        a[i] = -a[i];
    sort(a,a+k);
    for (int i = 0;i < k;++i)
        a[i] = -a[i];
    memset(f,0xff,sizeof(f));
    cout << F(0,n) << endl;
    return 0;
}