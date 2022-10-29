#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, k, sf[3000001], mx[10001];
vector<ll> v[30];
string s, d;

void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    n=a+b;
    if (b==1)
    {
        if (k>0) cout << "No\n";else
        {
            cout << "Yes\n";
            cout << "1";
            for (int i = 0; i < a; i++) cout << "0";
            cout << "\n";
            cout << "1";
            for (int i = 0; i < a; i++) cout << "0";
            cout << "\n";
        }
        return;
    }
    if (a==0)
    {
        if (k>0) cout << "No\n"; else
        {
            cout << "Yes\n";
            for (int i = 1; i <= b; i++) cout << "1";
            cout << "\n";
            for (int i = 1; i <= b; i++) cout << "1";
            cout << "\n";
        }
        return;
    }
    if (k>=a+b-1)
    {
        cout << "No\n";
        return;
    }
    s="1";
    d="1";
    while (s.size()<n) s+='0', d+='0';
    d.back()='1';
    ll o=n-k-1;
    s[o]='1';
    b-=2;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='0' && d[i]=='0' && b)
        {
            s[i]='1';
            d[i]='1';
            b--;
        }
    }
    cout << "Yes\n";
    cout << s << "\n";
    cout << d << "\n";
}

string gt(ll h)
{
    string p="";
    while (h)
    {
        p+=(h%2+'0');
        h/=2;
    }
    reverse(all(p));
    return p;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    /*for (int i = 0; i < (1<<10); i++)
    {
        ll x=i, z=0;
        while (x)
        {
            z+=x%2;
            x/=2;
        }
        for (int j = 0; j < i; j++)
        {
            ll y=j, o=0;
            while (y)
            {
                o+=y%2;
                y/=2;
            }
            if (z==o)
            {
                ll k=i-j, kk=k,  p=0;
                while (k)
                {
                    p+=k%2;
                    k/=2;
                }
                if (mx[10-z]<p)
                {
                    cout << z+1 << " " << gt(i+(1<<10)) << " " << gt(j+(1<<10)) << " " << gt(kk) << " " << p << "\n";
                 }
                mx[10-z]=max(mx[10-z], p);
            }
        }
    }
    for (int i = 0; i <= 10; i++)
    {
        cout << i << " " << mx[i] << "\n";
    }*/
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
......
MMMC
......
CCCM
.X..X.
MMM
XXXXXX
CMMCM
......
MM

*/