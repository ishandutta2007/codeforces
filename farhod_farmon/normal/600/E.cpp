#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int c[N];
int s[N];
int cnt[N];
long long ans[N];
vector < int > v[N];
map < int, int > *t[N];

void dfs(int x, int p)
{
        s[x] = 1;
        int big = -1, mx = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                s[x] += s[y];
                if(s[y] > mx){
                        mx = s[y];
                        big = y;
                }
        }
        if(s[x] == 1){
                ans[x] = c[x];
                cnt[x] = 1;
                t[x] = new map < int, int >;
                (*t[x])[c[x]] = 1;
                return;
        }
        else{
                t[x] = t[big];
                ans[x] = ans[big];
                cnt[x] = cnt[big];
                (*t[x])[c[x]]++;
                if((*t[x])[c[x]] > cnt[x]){
                        cnt[x] = (*t[x])[c[x]];
                        ans[x] = c[x];
                }
                else if((*t[x])[c[x]] == cnt[x]){
                        ans[x] += c[x];
                }
        }
        for(int y: v[x]){
                if(y == p || y == big){
                        continue;
                }
                for(auto p: *t[y]){
                        (*t[x])[p.fi] += p.se;
                        if((*t[x])[p.fi] > cnt[x]){
                                cnt[x] = (*t[x])[p.fi];
                                ans[x] = p.fi;
                        }
                        else if((*t[x])[p.fi] == cnt[x]){
                                ans[x] += p.fi;
                        }
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
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