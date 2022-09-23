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
const long long MX = 1000100;
const long long MAGIC = 1000;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int k;
int q;
int a[N];
set < int > s[N];
vector < int > v[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                v[x].pb(a[l]);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        int j = 0;
        for(int i = 0; i < v[x * 2].size(); i++){
                while(j < v[x * 2 + 1].size() && v[x * 2 + 1][j] < v[x * 2][i]){
                        v[x].pb(v[x * 2 + 1][j]);
                        j++;
                }
                v[x].pb(v[x * 2][i]);
        }
        while(j < v[x * 2 + 1].size()){
                v[x].pb(v[x * 2 + 1][j]);
                j++;
        }
}

int get(int x, int l, int r, int nl, int nr, int y)
{
        if(nl > nr){
                return 0;
        }
        if(l == nl && r == nr){
                if(v[x][0] >= y){
                        return 0;
                }
                int tl = 0, tr = v[x].size() - 1;
                while(tl < tr){
                        int tm = (tl + tr) / 2;
                        if(v[x][tm + 1] < y){
                                tl = tm + 1;
                        }
                        else{
                                tr = tm;
                        }
                }
                return tl + 1;
        }
        int m = (l + r) / 2;
        return get(x * 2, l, m, nl, min(m, nr), y) + get(x * 2 + 1, m + 1, r, max(m + 1, nl), nr, y);
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(s[x].size() == k){
                        a[i] = *s[x].begin();
                }
                s[x].insert(i);
                if(s[x].size() > k){
                        s[x].erase(s[x].begin());
                }
        }
        build(1, 1, n);
        cin >> q;
        int ans = 0;
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                l = (l + ans) % n + 1;
                r = (r + ans) % n + 1;
                if(l > r){
                        swap(l, r);
                }
                ans = get(1, 1, n, l, r, l);
                cout << ans << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("fcount.in");
        //fout("fcount.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}