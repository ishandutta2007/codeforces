#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];
int f[33];
int l[N];
int d[N][33];

int get(int tl, int tr)
{
        int g = l[tr - tl + 1];
        return max(d[tl][g], d[tr - (1 << g) + 1][g]);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                d[i][0] = a[i];
                if(i > 1){
                        l[i] = l[i / 2] + 1;
                }
        }
        for(int i = 1; i < 25; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 <= n){
                                d[j][i] = max(d[j][i - 1], d[j + (1 << i) / 2][i - 1]);
                        }
                }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                vector < pair < int, int > > g;
                for(int j = 0; j < 31; j++){
                        if((a[i] & (1 << j))){
                                f[j] = i;
                        }
                        if(f[j]){
                                g.push_back({f[j], j});
                        }
                }
                sort(g.begin(), g.end());
                reverse(g.begin(), g.end());
                int x = 0, r = i + 1;
                for(auto p: g){
                        x += (1 << p.se);
                        r = min(r, p.fi + 1);
                        int l = 1;
                        ans += r;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(get(m, i) < x){
                                        r = m;
                                }
                                else{
                                        l = m + 1;
                                }
                        }
                        ans -= r;

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