#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long l, r, x, y;
map < long long, vector < long long > > d;
vector < pair < long long, long long > > v;

vector < pair < long long, long long > > get(long long x)
{
        vector < pair < long long, long long > > v;
        for(long long i = 2; i * i <= x; i++){
                long long y = 1;
                while(x % i == 0){
                        y *= i;
                        x /= i;
                }
                if(y > 1){
                        v.push_back({i, y});
                }
        }
        if(x > 1){
                v.push_back({x, x});
        }
        sort(v.begin(), v.end());
        return v;
}

int ans;
map < pair < long long, long long >, bool > used;

void go(int x, long long a, long long b)
{
        if(x == v.size()){
                if(used.find({a, b}) != used.end()){
                        return;
                }
                used[{a, b}] = 1;
                ans += (l <= a && a <= r && l <= b && b <= r);
                return;
        }
        go(x + 1, a * v[x].fi, b * v[x].se);
        go(x + 1, a * v[x].se, b * v[x].fi);
}

void solve()
{
        cin >> l >> r >> x >> y;
        if(y % x){
                cout << 0 << "\n";
                return;
        }
        vector < pair < long long, long long > > vx = get(x), vy = get(y);
        for(auto p: vx){
                d[p.fi].push_back(p.se);
        }
        for(auto p: vy){
                d[p.fi].push_back(p.se);
        }
        for(auto p: d){
                if(p.se.size() == 1){
                        v.push_back({p.se[0], 1});
                }
                else{
                        v.push_back({p.se[0], p.se[1]});
                }
        }
        go(0, 1, 1);
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}