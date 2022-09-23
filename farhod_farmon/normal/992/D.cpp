#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n, k;
long long a[N];
vector < pair < long long, long long > > v;

void solve()
{
        int ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                long long p = a[i], s = a[i] * k;
                ans += (p == s);
                for(int j = v.size() - 1; j >= 0; j--){
                        if(p > Q / v[j].fi){
                                break;
                        }
                        p *= v[j].fi;
                        if(v[j].fi == 1){
                                if(s < p && p <= s + v[j].se * k && (p - s) % k == 0){
                                        ans++;
                                }
                                s += v[j].se * k;
                        }
                        else{
                                s += v[j].fi * k;
                                ans += (p == s);
                        }
                }
                if(a[i] == 1){
                        if(v.empty() || v.back().fi != 1){
                                v.push_back({1, 1});
                        }
                        else{
                                v[v.size() - 1].se++;
                        }
                }
                else{
                        v.push_back({a[i], 1});
                }
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