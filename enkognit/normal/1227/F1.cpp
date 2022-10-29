    #include <bits/stdc++.h>
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define pll pair<ll,ll>
    #define se second
    #define fi first

    using namespace std;

    const ll MOD=998244353;

    ll n, m, k, l, r, i, j, a[1000001], dp[2001][4001];
    bool tt[1000001];
    string s[1000001];

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        dp[0][2000]=1;
        a[n]=a[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 2000+n; j++)
            {
                //if (j>1999)cout << dp[i][j] << " ";
                if (a[i]==a[i+1])
                {
                    dp[i+1][j]+=dp[i][j];
                    dp[i+1][j]%=MOD;
                }
                dp[i+1][j]=(dp[i+1][j]+(dp[i][j]*(m-2+(a[i]==a[i+1]))%MOD))%MOD;
                if (a[i]!=a[i+1])dp[i+1][j-1]+=dp[i][j], dp[i+1][j+1]+=dp[i][j], dp[i+1][j-1]%=MOD, dp[i+1][j+1]%=MOD;
            }
            //cout << "\n";
        }
        ll ans=0;
        for (int j = 2001; j <= 2000+n; j++) {ans=(ans+dp[n][j])%MOD;}
        cout << ans;
        return 0;
    }