#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int t[4 * N];

void upd(int x, int l, int r, int g, int y)
{
        if(l == r){
                t[x] = y;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, y);
        }
        else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
        t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < pair < int, int > > v;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                while(!v.empty() && a[i] > v.back().fi){
                        v.pop_back();
                }
                if(!v.empty()){
                        int g = get(1, 1, n, v.back().se + 1, i) + 1;
                        upd(1, 1, n, i, g);
                        ans = max(ans, g);
                }
                v.push_back({a[i], i});
        }
        cout << ans << "\n";
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