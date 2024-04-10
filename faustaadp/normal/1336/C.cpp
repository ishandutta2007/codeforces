#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll d[3030][3030], n, m, mo = 998244353, has;
string s, t;
ll depe(ll kir,ll kan)
{
    ll ret = d[kir][kan];
    if(ret == -1)
    {
        ll lihat = kan - kir + 1;
        ret = 0;
        if(kir == 0 && kan >= (m - 1))
            ret = 1;
        if(kir > 0)
        {
            if((kir - 1) >= m || s[lihat] == t[kir - 1])
                ret = (ret + depe(kir - 1, kan)) % mo;
        }
        if(kan < (n - 1))
        {
            if((kan + 1) >= m || s[lihat] == t[kan + 1])
                ret = (ret + depe(kir, kan + 1)) % mo;
        }
        // cout << kir << " " << kan << " " << ret << "\n";
    }
    return d[kir][kan] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    memset(d, -1, sizeof(d));
    cin >> s;
    cin >> t;
    n = s.length();
    m = t.length();
    for(ll i = 0; i < n; i++)
        if(i >= m || t[i] == s[0])
            has = (has + depe(i, i)) % mo;
    has = (has + has) % mo;
    cout << has << "\n";
}