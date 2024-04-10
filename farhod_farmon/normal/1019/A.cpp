#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3030;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
vector < int > g[N];
vector < int > v[N];
vector < long long > l[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int p, x;
                cin >> p >> x;
                v[p].push_back(x);
        }
        for(int i = 2; i <= m; i++){
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
                for(int j = 0; j < v[i].size(); j++){
                        g[j + 1].push_back(v[i][j]);
                }
        }
        for(int i = 1; i <= n; i++){
                sort(g[i].begin(), g[i].end());
                for(int x: l[i - 1]){
                        l[i].push_back(x);
                }
                for(int x: g[i]){
                        l[i].push_back(x);
                }
                sort(l[i].begin(), l[i].end());
        }
        long long ans = 1e18, cnt = 0, s = v[1].size();
        for(int i = n; i >= 1; i--){
                for(int x: g[i]){
                        s++;
                        cnt += x;
                        if(s > i){
                                ans = min(ans, cnt);
                        }
                }
                long long left = 0;
                if(s < i){
                        for(int j = 0; j < i - s; j++){
                                left += l[i - 1][j];
                        }
                }
                ans = min(ans, cnt + left);
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