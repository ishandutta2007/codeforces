#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define dl double long

using namespace std;

const int N = 35000 + 7;
const int NN = 1e2 + 7;
const long long mod = 998244353;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;
int a[N];
ll d[N];
ll f[N];
ll t[4 * N];
ll lz[4 * N];

void push(int x)
{
    lz[x + x] += lz[x];
    lz[x + x + 1] += lz[x];
    t[x + x] += lz[x];
    t[x + x + 1] += lz[x];
    lz[x] = 0;
}


void upd(int x, int l, int r, int tl, int tr, ll val)
{
    if(tl > tr)return;
    if(l == tl && r == tr){
        t[x] += val;
        lz[x] += val;
        return;
    }
    int m = (l + r) / 2;
    push(x);
    upd(x + x, l, m, tl, min(tr, m), val);
    upd(x + x + 1, m + 1, r , max(tl, m + 1), tr, val);
    t[x] = min(t[x + x], t[x + x + 1]);
}

ll get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)return 1e18;
    if(l == tl && r == tr)return t[x];
    int m = (l + r) / 2;
    push(x);
    return min(get(x + x, l, m, tl, min(tr, m)) ,
    get(x + x + 1, m + 1, r , max(tl, m + 1), tr));
}

void solve()
{
    cin >> n >> k;
    int val = 0;
    vector<int> ls(n + 1, 0), f(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(ls[a[i]] > 0){
            val -= ls[a[i]] - f[a[i]];
            val += i - f[a[i]];
        }else f[a[i]] = i;
        ls[a[i]] = i;
        d[i] = val;
    }
    for(int j = 2; j <= k; j++){
        for(int i = 1; i <= n; i++){
            f[i] = d[i];
            d[i] = 0;
            ls[i] = 0;
        }
        for(int i = 1; i <= 4 * n; i++){
            t[i] = lz[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(ls[a[i]] > 0){
                upd(1, 1, n, 1, ls[a[i]], -ls[a[i]] + i);
                //upd(1, 1, n, 1, i, i);
                //upd(1, 1, n, ls[a[i]] + 1, i, -i);
                ls[a[i]] = i;
            }else{
                ls[a[i]] = i;
            }
            d[i] = get(1, 1, n, 1, i);
            if(i < n)upd(1, 1, n, i + 1, i + 1, f[i]);
        }
    }
    cout << d[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}