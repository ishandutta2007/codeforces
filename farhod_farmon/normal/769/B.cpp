#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 1e4 + 1;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
vector < pair < int, int > > v;
vector < pair < int, int > > ans;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1)
            v.pb({a[i], i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector < int > g;
    int h = 0;
    g.pb(1);
    for(auto ii: v){
        int i = ii.se;
        int x = g[h];
        while(a[x] == 0){
            if(h + 1 == g.size()){
                cout << -1 << "\n";
                return;
            }
            h++;
            x = g[h];
        }
        ans.pb({x, i});
        g.pb(i);
        a[x]--;
    }
    cout << ans.size() << "\n";
    for(auto p: ans)
        cout << p.fi << " " << p.se << "\n";
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}