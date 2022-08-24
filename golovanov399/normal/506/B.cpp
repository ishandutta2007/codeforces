#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

#define time alkdjfskjdfhk

const int N = 100010;
int tout[N];
bool was[N];
vector<int> a[N], b[N];
vector<vector<int> > comp;
int time = 0;
int color[N];
int cur;

void dfs(int v){
    for (auto x : a[v]){
        if (!was[x]){
            was[x] = true;
            dfs(x);
        }
    }
    tout[v] = time++;
}

void dfs2(int v){
    for (auto x : b[v]){
        if (!was[x]){
            was[x] = true;
            dfs2(x);
        }
    }
    comp.back().pb(v);
}

void dfs3(int v){
    for (auto x : a[v]){
        if (!was[x]){
            was[x] = true;
            // cerr << v + 1 << " -- " << x + 1 << "\n";
            dfs3(x);
        }
    }
    for (auto x : b[v]){
        if (!was[x]){
            was[x] = true;
            // cerr << v + 1 << " -- " << x + 1 << "\n";
            dfs3(x);
        }
    }
    color[v] = cur;
}

bool cmp(int x, int y){
    return (tout[x] > tout[y]);
}

int main(){

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].pb(y);
        b[y].pb(x);
    }
    for (int i = 0; i < n; i++){
        if (!was[i]){
            was[i] = true;
            dfs(i);
        }
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++)
        ord[i] = i;
    sort(all(ord), &cmp);
    for (int i = 0; i < n; i++){
        was[i] = false;
    }
    for (int i = 0; i < n; i++){
        if (!was[ord[i]]){
            comp.pb(vector<int>(0));
            was[ord[i]] = true;
            dfs2(ord[i]);
        }
    }
    cur = 0;
    for (int i = 0; i < n; i++)
        was[i] = false;
    for (int i = 0; i < n; i++){
        if (!was[i]){
            was[i] = true;
            dfs3(i);
            cur++;
        }
    }

    // for (int i = 0; i < n; i++)
    //  cerr << color[i] << " ";
    // cerr << "\n";

    int ans = 0;

    vector<int> cnt(cur);
    for (int i = 0; i < n; i++){
        cnt[color[i]]++;
    }

    vector<bool> ok(cur, 0);
    for (auto x : comp)
        if (x.size() > 1)
            ok[color[x[0]]] = true;

    for (int i = 0; i < cur; i++){
        if (ok[i])
            ans += cnt[i];
        else
            ans += cnt[i] - 1;
    }

    cout << ans << "\n";

    return 0;
}