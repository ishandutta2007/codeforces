#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int w[N];
int p[N];
int c[N];
vector < pair < int, int > > v;

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i] >> b[i] >> w[i];
                v.push_back({w[i], i});
        }
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans = 0;
        for(auto pp: v){
                int h = pp.se;
                int x = get(a[h]), y = get(b[h]);
                if(c[x] && c[y]){
                        continue;
                }
                if(y != x){
                        ans += w[h];
                        c[x] |= c[y];
                        p[y] = x;
                }
                else{
                        ans += w[h];
                        c[x] = 1;
                }
        }
        cout << ans << "\n";
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