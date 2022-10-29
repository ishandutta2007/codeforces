#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k, i, j, l, r, ans, a[200001];
ll b[100001];
short t[100001];

int main()
{
    cin >> n >> m >> k;
    cin >> a[0];
    ans=n;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        b[i]=a[i]-a[i-1]-1;
        //cout << b[i]
    }
    n--;
    sort(b+1,b+n+1);
    for (int i = 1; i <= n-k+1; i++)
    {
        //cout << b[i] << "\n";
        ans+=b[i];
    }
    cout << ans;
    return 0;
}