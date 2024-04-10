#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 200200;
const long long mod = 998244353;
const long long MAGIC = sqrt(N);

using namespace std;

long long gm(long long x)
{
        long long l = 1, r = 1e8;
        while(l < r){
                long long m = (l + r) / 2 + 1;
                if(m * m <= x){
                        l = m;
                }
                else{
                        r = m - 1;
                }
        }
        return l;
}

vector < pair < long long, long long > > f(long long x)
{
        vector < pair < long long, long long > > v;
        long long l = gm(x);
        for(long long i = 1; i <= l; i++){
                if(x % i == 0){
                        v.push_back({i, x / i});
                }
        }
        return v;
}

void solve()
{
        long long x, y;
        cin >> x >> y;
        vector < pair < long long, long long > > ab = f(x + y), a = f(x), b = f(y);
        long long ans = 1e18;
        for(auto p: ab){
                bool good = false;
                for(auto g: a){
                        good |= (g.fi <= p.fi && g.se <= p.se);
                }
                for(auto g: b){
                        good |= (g.fi <= p.fi && g.se <= p.se);
                }
                if(good){
                        ans = min(ans, p.fi + p.fi + p.se + p.se);
                }
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