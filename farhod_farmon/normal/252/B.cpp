#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

pair < int, int > lmin[N], rmin[N], lmax[N], rmax[N];
int n, x[N], i, j, h, ans[4];

void can(vector < pair < int, int > > v)
{
    if(v[0].fi == v[1].fi || v[1].fi == v[2].fi || v[0].fi == v[2].fi){
        if(v[0].fi == v[1].fi && v[1].fi == v[2].fi)
            return;
        if(v[0].fi == v[2].fi)
            return;
        if(v[0].fi == v[1].fi)
            cout << v[1].se << " " << v[2].se << endl;
        else if(v[0].fi == v[2].fi)
            cout << v[0].se << " " << v[2].se << endl;
        else
            cout << v[0].se << " " << v[1].se << endl;
        exit(0);
    }
    if(v[0].fi > v[1].fi && v[1].fi > v[2].fi || v[0].fi < v[1].fi && v[1].fi < v[2].fi){
        cout << v[0].se << " " << v[1].se << endl;
        exit(0);
    }
    else{
        cout << v[0].se << " " << v[2].se << endl;
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> x[i];
        if( i > 1 )
            lmin[i] = lmin[i - 1],
            lmax[i] = lmax[i - 1];
        else
            lmin[i] = {x[i], i},
            lmax[i] = {x[i], i};
        if(x[i] < lmin[i].fi);
            lmin[i] = {x[i], i};
        if(x[i] > lmax[i].fi)
            lmax[i] = {x[i], i};
    }
    for(i = n; i >= 1; i--){
        if( i < n )
            rmin[i] = rmin[i + 1],
            rmax[i] = rmax[i + 1];
        else
            rmin[i] = {x[i], i},
            rmax[i] = {x[i], i};
        if(x[i] < rmin[i].fi);
            rmin[i] = {x[i], i};
        if(x[i] > rmax[i].fi)
            rmax[i] = {x[i], i};
    }
    for(i = 2; i <= n - 1; i++){
        vector < pair < int, int > > v;
        v.pb(lmin[i - 1]);
        v.pb({x[i], i});
        v.pb(rmax[i + 1]);
        can(v);
        v[0] = lmax[i - 1];
        v[1] = {x[i], i};
        v[2] = rmin[i + 1];
        can(v);
        v[0] = lmax[i - 1];
        v[1] = {x[i], i};
        v[2] = rmax[i + 1];
        can(v);
        v[0] = lmin[i - 1];
        v[1] = {x[i], i};
        v[2] = rmin[i + 1];
        can(v);
    }
    cout << -1 << endl;
}