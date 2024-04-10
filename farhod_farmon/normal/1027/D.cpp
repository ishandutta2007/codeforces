#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int mn;
int a[N];
int c[N];
int d[N];
bool used[N];

void dfs(int x)
{
        if(used[x]){
                return;
        }
        used[x] = 1;
        mn = min(mn, c[x]);
        dfs(a[x]);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                d[a[i]]++;
        }
        queue < int > q;
        for(int i = 1; i <= n; i++){
                if(d[i] == 0){
                        q.push(i);
                        used[i] = true;
                }
        }
        while(!q.empty()){
                int x = q.front();
                q.pop();
                d[a[x]]--;
                if(d[a[x]] == 0){
                        q.push(a[x]);
                        used[a[x]] = true;
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
                mn = 1e9;
                if(used[i] == 0){
                        dfs(i);
                        ans += mn;
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