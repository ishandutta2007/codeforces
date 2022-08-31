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
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

LL ans = 0, Ans = 0;
vector<LL> a, b;
vector<int> cnt;
vector<vector<int> > d;
vector<bool> used;

LL gcd(LL x, LL y){
    while (y > 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

void dfs(int v){
    used[v] = true;
    vector<LL> A;
    vector<LL> B;
    for (int i = 0; i < d[v].size(); i++){
        if (!used[d[v][i]]){
            dfs(d[v][i]);
            cnt[v] += cnt[d[v][i]];
            A.pb(a[d[v][i]]);
            B.pb(b[d[v][i]]);
        }
    }
    if (cnt[v] == 0){
        b[v] = 1;
        cnt[v] = 1;
        return;
    }
    LL m = 1000000000000000;
    LL qw = 1;
    for (int i = 0; i < A.size(); i++){
        m = min(m, A[i]);
    }
    bool flag = false;
    for (int i = 0; i < B.size(); i++){
        if (B[i] == -1) flag = true;
    }
    if (flag){
        for (int i = 0; i < A.size(); i++) if (A[i] != m){
            cout << Ans << "\n";
            exit(0);
        }
        b[v] = -1;
        a[v] = m * A.size();
        return;
    }
    for (int i = 0; i < B.size(); i++){
        qw = qw * B[i] / gcd(qw, B[i]);
        if (B[i] > m || qw > m){
            cout << Ans << "\n";
            exit(0);
        }
    }
    b[v] = qw * A.size();
    if (b[v] > 1e9) b[v] = -1;
    m -= (m % qw);
    for (int i = 0; i < A.size(); i++){
        ans += A[i] - m;
    }
    a[v] = m * A.size();
}

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        Ans += a[i];
    }
    b.resize(n);
    d.resize(n);
    cnt.resize(n, 0);
    used.resize(n, false);
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        d[x].pb(y);
        d[y].pb(x);
    }
    dfs(0);
    cout << ans << "\n";

    return 0;
}