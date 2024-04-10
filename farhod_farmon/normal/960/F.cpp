#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int q;
int a[N];
int b[N];
int c[N];
vector < int > t[N];
vector < int > v[N];

void upd(int x, int g, int w)
{
        int f = v[x].size();
        while(g < f){
                t[x][g] = max(t[x][g], w);
                g += g & -g;
        }
}

int get(int x, int g)
{
        int cnt = 0;
        while(g > 0){
                cnt = max(cnt, t[x][g]);
                g -= g & -g;
        }
        return cnt;
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= q; i++){
                cin >> a[i] >> b[i] >> c[i];
                v[b[i]].push_back(c[i]);
                t[b[i]].push_back(0);
        }
        for(int i = 1; i <= n; i++){
                v[i].push_back(-1);
                t[i].push_back(0);
                sort(v[i].begin(), v[i].end());
        }
        int ans = 0;
        for(int i = 1; i <= q; i++){
                int x = a[i], y = b[i], w = c[i], mx = 0;
                if(v[x].size() > 0){
                        int l = 0, r = v[x].size() - 1;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(v[x][m + 1] < w){
                                        l = m + 1;
                                }
                                else{
                                        r = m;
                                }
                        }
                        mx = get(x, l);
                }
                ans = max(ans, mx + 1);
                int l = 0, r = v[y].size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(v[y][m] < w){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                upd(y, l, mx + 1);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}