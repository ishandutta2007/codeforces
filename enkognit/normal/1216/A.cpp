#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second

using namespace std;

ll n, m, k, i, j, l, r, a[1000001];

int main()
{
    string s;
    cin >> n;
    cin >> s;
    ll ans=0;
    for (int i = 0; i < n-1; i+=2)
        if (s[i]==s[i+1])
        {
            ans++;
            if (s[i]=='a') s[i]='b'; else s[i]='a';
        }
    cout << ans << "\n";
    cout << s;
    return 0;
}