#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

long long ans = 0;
int n, p, s[N], c[N], sz[N];
vector < int > v[N];
map < pair < int, int >, int > cnt;
bool used[N];

void solve(int x)
{
    int col = s[n] - s[max(0, p - sz[x])] + c[max(0, p - sz[x])];
    if(sz[x] + sz[x] >= p)
        col--;
    for(auto y: v[x])
        if(sz[y] + sz[x] >= p && sz[y] + sz[x] - cnt[{x, y}] < p)
            col--;
    ans += col;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        cnt[{x, y}]++;
        cnt[{y, x}]++;
        sz[x]++;
        sz[y]++;
        if(cnt[{x, y}] == 1){
            v[x].pb(y);
            v[y].pb(x);
        }
    }
    for(int i = 1; i <= n; i++)
        c[sz[i]]++;
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + c[i];
    for(int i = 1; i <= n; i++)
        solve(i);
    cout << ans / 2 << endl;
}