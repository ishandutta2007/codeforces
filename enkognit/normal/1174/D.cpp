#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, a[1000005];
vector <ll> v, ans;
vector <ll> c[500005];
map<ll,bool> tt;
set<ll> s;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> x;
    ll p=0;
    while (1)
    {
        bool t=0;
        for (ll i = 0; i < n; i++)
            if ((1<<i)!=x)
            {
                ll m=p^(1ll<<i);
                if (m!=0 && m!=x && tt[m^x]==0 && tt[m]==0) {t=1;tt[m]=1;p=m;ans.pb(1ll<<i);break;}
            }
        if (!t) break;
        //cout << ans[ans.size()-1] << " " << p << "\n";
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/