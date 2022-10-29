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

ll n, m, i, j, x, a[300005], ans;
string s, d;
vector <ll> c[300005], v, p;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    ll t=0, r=pow(2,32), q=1, x=0;
    cin >> t;
    //cout << r << "\n";
    while (t--)
    {
        cin >> s;
        if (s[0]=='f')
        {
            ll o;
            cin >> o;
            if (p.size()==0)
            {
                if (o>=r) p.pb(0); else p.pb(o);
            }else
            if (p[p.size()-1]*o>=r) p.pb(0);else p.pb(p[p.size()-1]*o);
        }else
        if (s[0]=='e')
        {
            p.erase(p.end()-1);
        }else
        if (s[0]=='a')
        {
            //if (p.size()) cout << p[p.size()-1] << "\n";
            if (p.size()==0)
            {
                x++;
                if (x>=r) {cout << "OVERFLOW!!!";exit(0);}
            }else
            if (p[p.size()-1]==0) {cout << "OVERFLOW!!!";exit(0);}else
            if (p[p.size()-1]+x>=r) {cout << "OVERFLOW!!!";exit(0);}else
            x+=p[p.size()-1];
        }
    }
    cout << x;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/