#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, s;
int a[N][3];
vector < pair < int, int > > ans;
map < pair < int, int >, vector < pair < int, int > > > u;

void f(int x, int y, pair < int, int > p)
{
    vector < pair < int, int > > v = u[{x, y}];
    if(v.size() == 0){
        v.resize(2);
        v[0] = v[1] = {0, 0};
    }
    if(v[0].se == p.se || v[1].se == p.se)
        return;
    if(v[0].fi < p.fi){
        v[1] = v[0];
        v[0] = p;
    }
    else if(v[1].fi < p.fi)
        v[1] = p;
    u[{x, y}] = v;
}

void upd(int x, int y)
{
    int z = 0;
    vector < pair < int, int > > v = u[{x, y}];
    for(auto p: v)
        z += p.fi;
    z = min(z, x);
    z = min(z, y);
    if(z > s){
        s = z;
        ans = v;
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        sort(a[i], a[i] + 3);
        f(a[i][0], a[i][1], {a[i][2], i});
        f(a[i][0], a[i][2], {a[i][1], i});
        f(a[i][1], a[i][2], {a[i][0], i});
    }
    for(int i = 1; i <= n; i++){
        upd(a[i][0], a[i][1]);
        upd(a[i][0], a[i][2]);
        upd(a[i][1], a[i][2]);
    }
    if(ans[1].se == 0)
        ans.pop_back();
    cout << ans.size() << endl;
    for(auto x: ans)
        cout << x.se << " ";
}