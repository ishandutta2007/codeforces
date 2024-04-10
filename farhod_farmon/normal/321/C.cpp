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
const long long MX = sqrt(N);
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int s[N];
vector < int > v[N];

void dfs(int x, int p)
{
        s[x] = 1;
        for(int y: v[x]){
                if(y == p || a[y]){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
        }
}

int get(int x, int p, int sz)
{
        int mx = sz - s[x];
        for(int y: v[x]){
                if(y == p || a[y]){
                        continue;
                }
                int ce = get(y, x, sz);
                if(ce != -1){
                        return ce;
                }
                mx = max(mx, s[y]);
        }
        if(mx <= sz / 2){
                return x;
        }
        return -1;
}

void dv(int x, int f)
{
        dfs(x, -1);
        x = get(x, -1, s[x]);
        a[x] = f;
        for(int y: v[x]){
                if(!a[y]){
                        dv(y, f + 1);
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].pb(y);
                v[y].pb(x);
        }
        dv(1, 1);
        for(int i = 1; i <= n; i++){
                cout << char('A' + a[i] - 1) << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}