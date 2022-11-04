#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

#define ll int

const ll MAXN=1e5+10;

set <ll> c0;
set <ll> c1;

vector <ll> f[MAXN];
vector <ll> w[MAXN];

ll a[MAXN];
ll x[MAXN];
ll fen[MAXN];

char s[MAXN];

void update(ll id , ll val)
{
    id+=2;
    for(;id<MAXN;id+=LB(id))
    {
        fen[id]+=val;
    }
}

ll get_sum(ll id)
{
    id+=2;
    ll sum=0;
    for(;id>0;id-=LB(id))
    {
        sum+=fen[id];
    }

    return sum;
}

ll getl(set <ll>& z)
{
    if (z.size()==0)
    {
        return -1;
    }

    set <ll> :: iterator h=z.end();
    h--;
    return (*h);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , q;
	cin>>n>>q;

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        f[abs(a[i])].pb(i);
    }

    for(ll i=1;i<=q;i++)
    {
        cin>>s[i]>>x[i];

        if (s[i]=='<' && x[i]>=0)
        {
            update(i , 1);
        }

        if (s[i]=='>' && x[i]<0)
        {
            update(i , 1);
        }

        w[abs(x[i])].pb(i);
    }

    for(ll i=0;i<MAXN;i++)
    {
        for(ll j=0;j<w[i].size();j++)
        {
            ll id=w[i][j];

            if (s[id]=='<')
            {
                if (x[id]>=0)
                {
                    update(id , -1);
                    c1.insert(id);
                }
            }

            if (s[id]=='>')
            {
                if (x[id]<0)
                {
                    update(id , -1);
                    c0.insert(id);
                }
            }
        }

        if (i>0)
        {
            for(ll j=0;j<w[i-1].size();j++)
            {
                ll id=w[i-1][j];

                if (s[id]=='<')
                {
                    if (x[id]<0)
                    {
                        c1.insert(id);
                    }
                }

                if (s[id]=='>')
                {
                    if (x[id]>=0)
                    {
                        c0.insert(id);
                    }
                }
            }
        }

        ll d=getl(c0) , z=0;

        if (getl(c1)>d)
        {
            d=getl(c1);
            z=1;
        }

        ll k=get_sum(MAXN-3)-get_sum(d);

        for(ll j=0;j<f[i].size();j++)
        {
            if (d!=-1)
            {
                a[f[i][j]]=abs(a[f[i][j]]);

                if (z==0)
                {
                    a[f[i][j]]*=-1;
                }
            }

            if (k&1)
            {
                a[f[i][j]]*=-1;
            }
        }
    }

    for(ll i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
}

/*
11 2
-5 -4 -3 -2 -1 0 1 2 3 4 5
> 2
> -4
*/