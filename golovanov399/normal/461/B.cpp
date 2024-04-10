#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

const int base = 1000000007;

vector<vector<int> > a;
vector<int> c;
vector<bool> used;

LL pw(LL a, LL b){
    LL res = 1;
    while (b > 0){
        if (b & 1){
            res = (res * a) % base;
        }
        a = (a * a) % base;
        b >>= 1;
    }
    return res;
}

LL inv(LL x){
    return pw(x, base - 2);
}

pair<LL, LL> dfs(int v){
    used[v] = true;
    LL ans = 0;
    LL w = 1;
    pair<LL, LL> p;
    if (c[v] == 1){
        for (int i = 0; i < a[v].size(); i++){
            if (!used[a[v][i]]){
                p = dfs(a[v][i]);
//              ans = (ans * p.first) % base;
                w = (w * p.second) % base;
            }
        }
//      cerr << v << " " << w << " " << 1 << "\n";
        return mp(w, w);
    } else {
        for (int i = 0; i < a[v].size(); i++){
            if (!used[a[v][i]]){
                p = dfs(a[v][i]);
                ans = (ans + p.first * inv(p.second)) % base;
                w = (w * p.second) % base;
            }
        }
        ans = (ans * w) % base;
//      cerr << v << " " << ans << " " << w + ans << "\n";
        return mp(ans, (w + ans) % base);
    }
}

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        a[i + 1].pb(x);
        a[x].pb(i + 1);
    }
    c.resize(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    used.resize(n, false);
    cout << dfs(0).first << "\n";
    
    return 0;
}