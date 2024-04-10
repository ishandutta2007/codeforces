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

int n;
int m;
int a[N];
set < int > need;
vector < int > v[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[a[i] % m].push_back(i);
        }
        long long ans = 0, ans2 = 0;
        vector < pair < int, int > > g;
        for(int i = 0; i < m + m; i++){
                while(v[i % m].size() > n / m){
                        g.push_back({v[i % m].back(), i});
                        v[i % m].pop_back();
                }
                while(v[i % m].size() < n / m && !g.empty()){
                        v[i % m].push_back(g.back().fi);
                        a[g.back().fi] += i - g.back().se;
                        ans2 += i - g.back().se;
                        g.pop_back();
                }
                ans += g.size();
        }
        assert(ans == ans2);
        cout << ans << "\n";
        for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
        }
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