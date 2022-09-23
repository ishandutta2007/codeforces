#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long t[4 * N];
long long z[4 * N];

void push(int x, int l, int m, int r)
{
    if(!z[x])
        return;
    t[x * 2] += 1ll * (m - l + 1) * z[x];
    z[x * 2] += z[x];
    t[x * 2 + 1] += 1ll * (r - m) * z[x];
    z[x * 2 + 1] += z[x];
    z[x] = 0;
}

void upd(int x, int l, int r, int tl, int tr, int g)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        t[x] += 1ll * (r - l + 1) * g;
        z[x] += g;
        return;
    }
    int m = (l + r) / 2;
    push(x, l, m, r);
    upd(x * 2, l, m, tl, min(m, tr), g);
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
    t[x] = t[x * 2] + t[x * 2 + 1];
}

long long get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return 0;
    if(l == tl && r == tr)
        return t[x];
    int m = (l + r) / 2;
    push(x, l, m, r);
    return get(x * 2, l, m, tl, min(m, tr)) + get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int L = 200002;
int l = 1;
int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t, x, a;
        cin >> t;
        if(t == 1){
            cin >> a >> x;
            upd(1, 1, L, 1, a, x);
        }
        else if(t == 2){
            cin >> x;
            l = l + 1;
            upd(1, 1, L, l, l, x);
        }
        else{
            upd(1, 1, L, l, l, -get(1, 1, L, l, l));
            l = l - 1;
        }
        cout << fixed << setprecision(6) << 1.0 * get(1, 1, L, 1, l) / l << endl;
    }
}