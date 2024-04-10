#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int q;
int p[N];
bool us[N];
vector < int > v[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void solve()
{
        cin >> n >> m >> q;
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
                p[i] = i;
        }
        for(int i = 1; i <= n; i++){
                if(v[i].size() > 0){
                        for(int j = 1; j < v[i].size(); j++){
                                int x = get(v[i][j - 1]), y = get(v[i][j]);
                                if(x != y){
                                        p[x] = y;
                                }
                        }
                }
                else{
                        ans++;
                }
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++){
                int x = get(i);
                if(us[x] == 0){
                        us[x] = 1;
                        cnt++;
                }
        }
        cout << ans + cnt - 1 << "\n";
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