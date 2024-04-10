#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
vector < int > t[MX], v[4 * MX];

void build(int x, int l, int r)
{
        if(l == r){
                v[x] = t[l];
                sort(v[x].begin(), v[x].end());
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

int get(int x, int l, int r, int tl, int tr, int p)
{
        if(tl > tr){
                return 0;
        }
        if(v[x].empty()){
                return 0;
        }
        if(l == tl && r == tr){
                if(v[x].back() < p){
                        return 0;
                }
                int nl = 0, nr = v[x].size() - 1;
                while(nl < nr){
                        int m = (nl + nr) / 2;
                        if(v[x][m] < p){
                                nl = m + 1;
                        }
                        else{
                                nr = m;
                        }
                }
                return v[x].size() - nl;
        }
        int m = (l + r) / 2;
        return get(x * 2, l, m, tl, min(m, tr), p) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, p);
}

void solve()
{
        int m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                t[l].pb(r);
        }
        build(1, 1, MX - 1);
        for(int i = 1; i <= m; i++){
                int p, last = 0, s, cnt = 0;
                cin >> s;
                for(int j = 1; j <= s; j++){
                        cin >> p;
                        cnt += get(1, 1, MX - 1, last + 1, p, p);
                        last = p;
                }
                cout << cnt << endl;
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
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}