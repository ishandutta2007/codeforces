#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, k, b, r, ans, a[5001];
int dp[5001][5001][2];

int main()
{
    cin >> n;
    if (n%2)
    {
        bool tt=0;
        for (int i = 2; i <= sqrt(n); i++) if (n%i==0) {tt=1;break;}
        if (!tt) cout << 1; else
        if (n!=3)
        {
            ll l=n-2;
            bool tt=0;
            for (int i = 2; i <= sqrt(l); i++) if (l%i==0) {tt=1;break;}
            if (!tt) {cout << 2;exit(0);} else cout << 3;
        }else
        cout << 3;
    }else
    if (n==2) cout << 1; else
    cout << 2;
    return 0;
}