//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int maxn = 300111;
int n;
ll val[maxn], msk[maxn];
int main()
{
    scanf("%d", &n);
    ll SUM = 0;
    for (int i=1; i<=n; i++) scanf("%lld%lld", &val[i], &msk[i]), SUM += val[i];
    ll ans = 0;
    for (int i=0; i<62; i++)
    {
        ll sum = 0; 
        for (int j=1; j<=n; j++)
        {
            if ((msk[j]<(1ll<<i+1))&&((msk[j]>>i)&1))
            {
                sum += val[j];
            }
        }
        if (sum==0) continue;
        if ((sum>0)==(SUM>0))
        {
            ans |= 1ll<<i;
            for (int j=1; j<=n; j++)
            {
                if (((msk[j]>>i)&1))
                {
                    val[j] = -val[j];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}