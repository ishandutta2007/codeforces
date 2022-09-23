#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int f[N];
int g[N][2];
long long k;
long long a[N];

void upd(int x)
{
        while(x < N){
                f[x] += 1;
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 0;
        while(x > 0){
                cnt += f[x];
                x -= x & -x;
        }
        return cnt;
}

void solve()
{
        cin >> n >> k;
        vector < pair < long long, pair < int, int > > > v;
        v.push_back({0, {0, 0}});
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] += a[i - 1];
                v.push_back({a[i], {i, 0}});
                v.push_back({a[i] - k, {i, 1}});
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 1; i < v.size(); i++){
                if(i > 0 && v[i].fi != v[i - 1].fi){
                        j++;
                }
                g[v[i].se.fi][v[i].se.se] = j;
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                upd(g[i - 1][0]);
                ans += i - get(g[i][1]);
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