    #include <bits/stdc++.h>
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define fi first
    #define se second
    #define pll pair<ll,ll>

    using namespace std;

    ll MOD=1e9+7;

    ll n, m, k, l, r, i, j, kl, x, y;
    vector <ll> v[100005], c[100005];
    string s, d;

    ll binpow(ll k,ll h)
    {
        ll l=1, r=h, x=k;
        while (r)
        {
            if (r%2) l*=x, l%=MOD;
            x*=x;
            x%=MOD;
            r/=2;
        }
        return l;
    }

    int main()
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) v[i].pb(0);
        for (int i = 1; i <= m; i++) c[i].pb(0);
        for (int i = 0; i < k; i++)
        {
            ll x, y;
            cin >> x >> y;
            v[x].pb(y);
            c[y].pb(x);
        }
        for (int i = 1; i <= n; i++) {v[i].pb(m+1);sort(v[i].begin(),v[i].end());}
        for (int i = 1; i <= m; i++) {c[i].pb(n+1);sort(c[i].begin(),c[i].end());}
        ll kl=n*m-k-1, x=1, y=1, p=1, gv=1, gn=n, gl=1, gr=m;
        if (v[1][1]==2) p=2;
        while (kl>0)
        {
            //cout << x << " " << y << " " << kl << " " << p << ": " << gl << "-" << gr << " " << gv << "-" << gn << "\n";
            //if (gl==gr && gv==gn) break;
            if (p==1)
            {
                ll l=0, r=v[x].size()-1;
                while (l<r)
                {
                    ll w=(l+r)/2;
                    if (v[x][w]<=y) l=w+1; else r=w;
                }
                ll o=min(gr,v[x][l]-1);
                if (y==o) {cout << "No\n";exit(0);}
                kl-=abs(o-y), p=2, gv=x+1, y=o;
            }else
            if (p==2)
            {
                ll l=0, r=c[y].size()-1;
                while (l<r)
                {
                    ll w=(l+r)/2;
                    if (c[y][w]<=x) l=w+1; else r=w;
                }
                ll o=min(gn,c[y][l]-1);
                if (x==o) {cout << "No\n";exit(0);}
                kl-=abs(o-x), p=3, gr=y-1, x=o;
            }else
            if (p==3)
            {
                ll l=0, r=v[x].size()-1;
                while (l<r)
                {
                    ll w=(l+r+1)/2;
                    if (v[x][w]>=y) r=w-1; else l=w;
                }
                ll o=max(gl,v[x][l]+1);
                //cout << o << "\n";
                if (y==o) {cout << "No\n";exit(0);}
                kl-=abs(y-o), p=4, gn=x-1, y=o;
            }else
            if (p==4)
            {
                ll l=0, r=c[y].size()-1;
                while (l<r)
                {
                    ll w=(l+r+1)/2;
                    if (c[y][w]>=x) r=w-1; else l=w;
                }
                ll o=max(gv,c[y][l]+1);
                if (x==o) {cout << "No\n";exit(0);}
                kl-=abs(x-o), p=1, gl=y+1, x=o;
            }
        }
        if (kl) cout << "No\n"; else cout << "Yes\n";
        return 0;
    }