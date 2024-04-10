#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, p, g, l, r, ans=0, dp[2][200002];
string s, d;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> r >> g;
    if (r>g) swap(r,g);
    //cout << (ll)sqrt(r*2+g*2) << "\n";
    //for (int i = 0; i < (ll)sqrt(r*2+g*2)+10; i++)
        //for (int j = 0; j <= r; j++) dp[i][j]=0;
    dp[0][r]=1;
    ll k=0;
    for (int i = 0; i < 1000; i++)
    {
        k=-1;
        for (int j = 0; j <= r; j++)
            if (dp[0][j])
            {
                if (j>=i+1) dp[1][j-i-1]+=dp[0][j], dp[1][j-i-1]%=(ll)1e9+7, k=1;
                if (g-(i*(i+1)/2-r+j)>=i+1) dp[1][j]+=dp[0][j],k=1,dp[1][j]%=(ll)1e9+7;
            }
        if (k==-1) {p=i;break;}
        for (int j = 0; j <= r; j++) dp[0][j]=dp[1][j], dp[1][j]=0;
    }
    for (int i = 0; i <= r; i++) ans+=dp[0][i], ans%=(ll)1e9+7;
    cout << ans;
    return 0;
}
/*

*/