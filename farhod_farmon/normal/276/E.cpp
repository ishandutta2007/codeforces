#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

struct fee
{
        int n;
        vector < int > v;
        fee()
        {
                n = 1;
                v.push_back(0);
                v.push_back(0);
        }
        void add()
        {
                n++;
                v.push_back(0);
        }
        void upd(int x, int g)
        {
                x = max(x, 1);
                while(x <= n){
                        v[x] += g;
                        x += x & -x;
                }
        }
        int get(int x)
        {
                x = min(x, n);
                int cnt = 0;
                while(x > 0){
                        cnt += v[x];
                        x -= x & -x;
                }
                return cnt;
        }
};


fee t[N], all;
int n, q;
int c[N];
int f[N];
vector < int > v[N];

void dfs(int x, int p, int g1, int g2)
{
        c[x] = g1;
        f[x] = g2;
        t[g1].add();
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x, g1, g2 + 1);
        }
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                all.add();
        }
        int C = 0;
        for(int x: v[1]){
                ++C;
                dfs(x, 1, C, 1);
        }
        int for_1 = 0;
        for(int i = 1; i <= q; i++){
                int ty, x, y, d;
                cin >> ty >> x;
                if(ty){
                        if(x == 1){
                                cout << for_1 << "\n";
                        }
                        else{
                                cout << t[c[x]].get(f[x]) + all.get(f[x]) << "\n";
                        }
                }
                else{
                        cin >> y >> d;
                        if(f[x] - d <= 0){
                                for_1 += y;
                        }
                        if(x == 1){
                                all.upd(1, y);
                                all.upd(d + 1, -y);
                        }
                        else{
                                t[c[x]].upd(f[x] - d, y);
                                t[c[x]].upd(f[x] + d + 1, -y);
                                if(f[x] - d < 0){
                                        all.upd(1, y);
                                        all.upd(d - f[x] + 1, -y);
                                        t[c[x]].upd(1, -y);
                                        t[c[x]].upd(d - f[x] + 1, y);
                                }
                        }
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}