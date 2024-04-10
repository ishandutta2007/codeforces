#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );
#define ll int

const int N = 100100;
const long long mod = 1e15 + 3;

using namespace std;

int n;
int p[N];
int f[N];
int a[N];
int ans[N];
int t[4 * N];
int lazy[4 * N];

void push(int x)
{
    if(lazy[x] == 0)
        return;
    t[x * 2] += lazy[x];
    t[x * 2 + 1] += lazy[x];
    lazy[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
    lazy[x] = 0;
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        t[x] += g;
        lazy[x] += g;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr), g);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r)
{
    if(t[x] <= 0)
        return -1;
    if(l == r)
        return l;
    push(x);
    int m = (l + r) / 2;
    if(t[x * 2 + 1] > 0)
        return get(x * 2 + 1, m + 1, r);
    return get(x * 2, l, m);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i] >> f[i];
        if(f[i])
            cin >> a[i];
        if(f[i] == 0){
            upd(1, 1, n, 1, p[i], -1);
        }
        else{
            upd(1, 1, n, 1, p[i], 1);
            ans[p[i]] = a[i];
        }
        int x = get(1, 1, n);
        if(x == -1)
            cout << -1 << endl;
        else
            cout << ans[x] << endl;
    }
}