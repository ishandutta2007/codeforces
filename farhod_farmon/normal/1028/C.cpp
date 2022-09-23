#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 500500;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

int n;
pair < int, int > a[N];
pair < int, int > b[N];
pair < int, int > la[N];
pair < int, int > lb[N];
pair < int, int > ra[N];
pair < int, int > rb[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
        }
        la[0] = ra[n + 1] = {-1e9, -1e9};
        lb[0] = rb[n + 1] = {1e9, 1e9};
        for(int i = 1; i <= n; i++){
                la[i].fi = max(la[i - 1].fi, a[i].fi);
                la[i].se = max(la[i - 1].se, a[i].se);
                lb[i].fi = min(lb[i - 1].fi, b[i].fi);
                lb[i].se = min(lb[i - 1].se, b[i].se);
        }
        for(int i = n; i >= 1; i--){
                ra[i].fi = max(ra[i + 1].fi, a[i].fi);
                ra[i].se = max(ra[i + 1].se, a[i].se);
                rb[i].fi = min(rb[i + 1].fi, b[i].fi);
                rb[i].se = min(rb[i + 1].se, b[i].se);
        }
        for(int i = 1; i <= n; i++){
                pair < int, int > a, b;
                a.fi = max(la[i - 1].fi, ra[i + 1].fi);
                a.se = max(la[i - 1].se, ra[i + 1].se);
                b.fi = min(lb[i - 1].fi, rb[i + 1].fi);
                b.se = min(lb[i - 1].se, rb[i + 1].se);
                if(a.fi <= b.fi && a.se <= b.se){
                        cout << a.fi << " " << a.se << '\n';
                        return;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}