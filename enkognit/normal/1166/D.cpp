#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, ans, k, p, a[200001];
vector <ll> v;

ll bp(ll h,ll p)
{
    ll l=1, o=0;
    while (o<p)
    {
        if (o==0 || (o*2>p)) o++, l*=h; else l*=l, o*=2;
    }
    return l;
}

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll q;
    cin >> q;
    for (int it = 0; it < q; it++)
    {
        ll a, b, m, w=-1;
        vector <ll> z, q;
        cin >> a >> b >> m;
        if (b<=a+m && a<b)
        {
            cout << "2 " << a << " " << b << "\n";
            continue;
        }
        if (a==b) {cout << "1 "<< a << "\n";continue;}
        z.pb(0);
        //q.pb(0);
        z.pb(a);
        //q.pb(0);
        z.pb(a+1);
        //q.pb(1);
        for (int i = 0; i < 51; i++)
        {
            if (z[z.size()-1]*2>b) break;
            //if (z[z.size()-1]+bp(2,z.size()-2)*(m-1)>=b) break;
            z.pb(z[z.size()-1]*2);
            //q.pb(1);

        }
        //for (int i = 1; i < z.size(); i++) cout << z[i] << " ";
        //cout << "\n";
        if (z[z.size()-1]>b) {cout << "-1\n";continue;}
        //if (z[z.size()-1])
        //if ()
        for (int i = 2; i < z.size(); i++)
        {
            ll y=z.size()-2-i;
            if (z.size()-1==i) y=0;
            ll c=min((b-z[z.size()-1])/bp(2, y), m-1);
            z[i]+=c;
            for (int j = i+1; j < z.size(); j++)
            {
                z[j]+=c;
                c*=2;
            }
        }
        if (z[z.size()-1]!=b) {cout << "-1 \n";continue;}
        cout << z.size()-1 << " ";
        for (int i = 1; i < z.size(); i++) cout << z[i] << " ";
        cout << "\n";
    }
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4
bokutachi wa benkyou ga dekinai
*/