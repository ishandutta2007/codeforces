#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    static long long ad[6005][105];

    int n;
    cin>>n;

    int a[n], b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((__gcd( abs(a[j]-a[i]), abs(b[j]-b[i])) & 3) == 0)
            {
                ad[i][j>>6] |= (1LL<<(j&63));
            }
        }
    }

    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            if(ad[i][j>>6] & (1LL<<(j&63)))
            {
                ans += 64 - ((j+1)&63) - __builtin_popcountll((ad[i][(j+1)>>6]^ad[j][(j+1)>>6]) & (-(1LL<<((j+1)&63))));
                for(int k = ((j+1)>>6)+1; k <= ((n-1)>>6); k++)
                {
                    ans += 64 - __builtin_popcountll(ad[i][k]^ad[j][k]);
                }
                ans -= 63 - ((n-1)&63);
            }
            else
            {
                ans += __builtin_popcountll((ad[i][(j+1)>>6]^ad[j][(j+1)>>6]) & (-(1LL<<((j+1)&63))) );
                for(int k = ((j+1)>>6)+1; k <= ((n-1)>>6); k++)
                {
                    ans += __builtin_popcountll(ad[i][k]^ad[j][k]);
                }
            }
        }
    }
    cout<<ans;

    return 0;
}