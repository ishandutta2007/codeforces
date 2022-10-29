#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define y1 Enkognit
#define fi first
#define se second

using namespace std;

ll n, m, k, l, r, i, j, a[1000001], dp[100001];
ll w[10001];
vector <string> s, z;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0]=='M') w[0]++;
        if (s[s.size()-1]=='S') w[(s.size()-1)*10+1]++;
        if (s[s.size()-1]=='L') w[(s.size()-1)*10+2]++;
    }
    for (int i = 0; i < n; i++)
    {
        string d;
        cin >> d;
        if (d[0]=='M') w[0]--;
        if (d[d.size()-1]=='S') w[(d.size()-1)*10+1]--;
        if (d[d.size()-1]=='L') w[(d.size()-1)*10+2]--;
    }
    ll ans=0;
    for (int i = 0; i < 40; i++)
    ans+=abs(w[i]);cout << ans/2;
    return 0;
}