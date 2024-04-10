#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n, m;
int a[N];
int t[4 * N];
int lz[4 * N];
vector<int> b[N];

void build(int x, int l, int r)
{
    lz[x] = 0;
    if(l == r){
        t[x] = n - l + 1;
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = min(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
    if(tl > tr){
        return;
    } else if(l == tl && r == tr){
        t[x] += y;
        lz[x] += y;
        return;
    }
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), y);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
    t[x] = min(t[x * 2], t[x * 2 + 1]) + lz[x];
}

void upd(long long s, int k, int g)
{
    s = (s - 1) / k + 1;
    int l = 1, r = n + 1;
    while(l < r){
        int m = (l + r) / 2;
        if(s <= a[m]){
            r = m;
        } else{
            l = m + 1;
        }
    }
    upd(1, 1, n + 1, 1, l, -g);
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    build(1, 1, n + 1);
    for(int i = 1; i <= m; i++){
        int k;
        cin >> k;
        b[i].resize(k);
        long long sum = 0;
        for(int j = 0; j < k; j++){
            cin >> b[i][j];
            sum += b[i][j];
        }
        upd(sum, k, 1);
    }
    for(int i = 1; i <= m; i++){
        long long sum = 0;
        for(int j = 0; j < b[i].size(); j++){
            sum += b[i][j];
        }
        upd(sum, b[i].size(), -1);
        for(int j = 0; j < b[i].size(); j++){
            sum -= b[i][j];
            upd(sum, b[i].size() - 1, 1);
            if(t[1] < 0){
                cout << 0;
            } else{
                cout << 1;
            }
            upd(sum, b[i].size() - 1, -1);
            sum += b[i][j];
        }
        upd(sum, b[i].size(), 1);
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}