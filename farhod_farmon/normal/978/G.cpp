#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int a[N];
int b[N];
int c[N];
int f[N];
int ans[N];
vector < int > v[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i] >> b[i] >> c[i];
                f[b[i]] = i;
                v[a[i]].push_back(i);
        }
        set < pair < int, int > > s;
        for(int i = n; i >= 1; i--){
                if(f[i]){
                        ans[i] = m + 1;
                        s.insert({a[f[i]], f[i]});
                }
                else if(!s.empty()){
                        auto p = *(--s.end());
                        s.erase(p);
                        c[p.se]--;
                        ans[i] = p.se;
                        if(c[p.se] > 0){
                                s.insert(p);
                        }
                }
                for(int x: v[i]){
                        if(s.find({a[x], x}) != s.end()){
                                cout << -1 << "\n";
                                return;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
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