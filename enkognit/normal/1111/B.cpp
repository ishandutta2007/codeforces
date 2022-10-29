#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, j, l, r, kol;
ld k, ans, a[1000001], b[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i = n-1; i >= 0; i--) b[i]=a[i]+b[i+1];
    for (int i = n-1; i >= 0; i--)
    {
        //cout << i << " " << b[i] << "\n";
        if (i<=m)
            if (ans<b[i]/(n-i)+min((ld)(m-i),k*(n-i))/(n-i)) ans=b[i]/(n-i)+min((ld)(m-i),k*(n-i))/(n-i);
    }
    cout.precision(11);
    cout <<fixed<< ans;
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/