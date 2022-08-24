#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 100010;
int level[N], sz[N];
vector<int> a[N];

void dfs(int v){
    for (auto x : a[v]){
        if (level[x] == 0){
            level[x] = level[v] + 1;
            dfs(x);
            sz[v] += sz[x];
        }
    }
    sz[v]++;
}

int main(){

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > road(n - 1);
    for (int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
        road[i] = mp(mp(x, y), z);
    }
    level[0] = 1;
    dfs(0);
    double ans = 0;
    long long P = 1ll * n * (n - 1) * (n - 2) / 6;
    vector<double> f(n);
    for (int i = 0; i < n; i++){
        int cur = sz[i];
        f[i] = (double)(P - 1ll * cur * (cur - 1) * (cur - 2) / 6 - 1ll * (n - cur) * (n - cur - 1) * (n - cur - 2) / 6) / P;
    }
    for (auto x : road){
        int v = (level[x.x.x] < level[x.x.y]) ? x.x.y : x.x.x;
        ans += f[v] * x.y;
    }
    int q;
    cin >> q;
    cout << setprecision(10) << fixed;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        int cs = road[x].y - y;
        int v = (level[road[x].x.x] < level[road[x].x.y]) ? road[x].x.y : road[x].x.x;
        ans -= f[v] * cs;
        cout << 2 * ans << "\n";
        road[x].y = y;
    }

    return 0;
}