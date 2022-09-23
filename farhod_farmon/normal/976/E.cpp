#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

long long n;
long long a;
long long b;
long long h[N];
long long d[N];
long long cnt;
bool used[N];
vector < pair < long long, int > > v;

long long get(int x)
{
        if(!used[x]){
                return cnt;
        }
        return cnt - (h[x] - d[x]) + max(0ll, v[b - 1].fi);
}

void solve()
{
        long long s = 0;
        cin >> n >> a >> b;
        for(int i = 1; i <= n; i++){
                cin >> h[i] >> d[i];
                s += d[i];
                v.push_back({h[i] - d[i], i});
        }
        b = min(b, n);
        long long ans = s + cnt;
        if(b == 0){
                cout << ans << "\n";
                return;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        v.push_back({0, 0});
        for(int i = 0; i < b - 1; i++){
                if(v[i].fi > 0){
                        cnt += v[i].fi;
                        used[v[i].se] = 1;
                }
        }
        for(int i = 1; i <= n; i++){
                long long x = h[i];
                for(int j = 0; j < a; j++){
                        x += x;
                }
                ans = max(ans, s - d[i] + max(x, d[i]) + get(i));
        }
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