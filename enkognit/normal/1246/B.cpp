#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll md=1e9+7, md1=56145269, md2=998453261, md3=45113621, p1=54517, p2=481213, p3=217653;

ll n, m, k, l, r, i, j, kl, x, y, a[1000001], b[100001][3];
vector <pll> v[100005];
bool tt[1000001];
map <pair<pair<int,int>, int>, int> w;
string s;

ll binpow(ll h,ll k,ll md)
{
    ll l=1, r=k;
    while (r)
    {
        if (r%2) l*=h, l%=md;
        r/=2;
        h*=h, h%=md;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ll u=sqrt(a[i]);
        ll z=a[i];
        for (int j = 2; j <= u; j++)
            if (z%j==0)
            {
                ll o=0;
                while (z%j==0) z/=j, o++;
                o%=m;
                if (o>0)
                {
                    //if (i==1) cout << "------------------\n";
                    b[i][0]*=p1, b[i][0]+=j, b[i][0]%=md1, b[i][0]*=p1, b[i][0]+=o, b[i][0]%=md1;
                    b[i][1]*=p2, b[i][1]+=j, b[i][1]%=md2, b[i][1]*=p2, b[i][1]+=o, b[i][1]%=md2;
                    b[i][2]*=p3, b[i][2]+=j, b[i][2]%=md3, b[i][2]*=p3, b[i][2]+=o, b[i][2]%=md3;
                    v[i].pb(mp(j, o));
                }
            }
        if (z>1)
        {
            b[i][0]*=p1, b[i][0]+=z, b[i][0]%=md1, b[i][0]*=p1, b[i][0]+=1, b[i][0]%=md1;
            b[i][1]*=p2, b[i][1]+=z, b[i][1]%=md2, b[i][1]*=p2, b[i][1]+=1, b[i][1]%=md2;
            b[i][2]*=p3, b[i][2]+=z, b[i][2]%=md3, b[i][2]*=p3, b[i][2]+=1, b[i][2]%=md3;
            v[i].pb(mp(z,1));
        }
        w[mp(mp(b[i][0],b[i][1]),b[i][2])]++;
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        w[mp(mp(b[i][0],b[i][1]),b[i][2])]--;
        ll b0=0, b1=0, b2=0;
        //if (v[i].size()==0) ans+=w[mp(mp(b[i][0],b[i][1]),b[i][2])];
        //cout << i << "\n";
        //cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << "\n";
        for (int j = 0; j < v[i].size(); j++)
        {
            //cout << v[i][j].fi << " " << v[i][j].se << "\n";
            b0*=p1, b0+=v[i][j].fi, b0%=md1, b0*=p1, b0+=m-v[i][j].se, b0%=md1;
            b1*=p2, b1+=v[i][j].fi, b1%=md2, b1*=p2, b1+=m-v[i][j].se, b1%=md2;
            b2*=p3, b2+=v[i][j].fi, b2%=md3, b2*=p3, b2+=m-v[i][j].se, b2%=md3;
        }
        //cout << b0 << " " << b1 << " " << b2 << "\n";
        ans+=w[mp(mp(b0,b1),b2)];
    }
    cout << ans;
    return 0;
}