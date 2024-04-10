#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;

        int mn[2] = {1<<30, 1<<30};
        long long sm[2] = {0LL, 0LL};
        long long ans = (1LL<<60);
        for(int i=0; i<n; i++)
        {
            int t;
            cin>>t;

            mn[i&1] = min(mn[i&1], t);
            sm[i&1] += t;

            ans = min(ans, 1LL*mn[0]*(n-1-i/2) + sm[0] + 1LL*mn[1]*(n-(i+1)/2) + sm[1]);
        }

        cout<<ans<<'\n';
    }

    return 0;
}