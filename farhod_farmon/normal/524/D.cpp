#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 86400;

using namespace std;

int n, M, T;
int mx[4 * N + 100];
int lazy[4 * N + 100];

void push(int x)
{
    if(lazy[x] == 0)
        return;
    lazy[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
    mx[x * 2] += lazy[x];
    mx[x * 2 + 1] += lazy[x];
    lazy[x] = 0;
}

void upd(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return;
    if(l == tl && r == tr){
        lazy[x]++;
        mx[x]++;
        return;
    }
    push(x);
    int m = (l + r) / 2;
    upd(x * 2, l, m, tl, min(m, tr));
    upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
    mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return 0;
    if(l == tl && r == tr)
        return mx[x];
    push(x);
    int m = (l + r) / 2;
    return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d %d %d\n", &n, &M, &T);
    int last = 0,
        id = 0;
    vector < int > v;
    for(int i = 1; i <= n; i++){
        int l, ll, lll, r;
        sc("%d:%d:%d\n", &l, &ll, &lll);
        l = l * 60 * 60 + ll * 60 + lll + 1;
        r = l + T - 1;
        int x = get(1, 1, N, l, r);
        if(x + 1 <= M){
            upd(1, 1, N, l, r);
            v.pb(++id);
        }
        else{
            upd(1, 1, N, last + T, r);
            v.pb(id);
        }
        last = l;
    }
    if(get(1, 1, N, 1, N) != M){
        pr("No solution\n");
        return 0;
    }
    pr("%d\n", id);
    for(int i = 0; i < v.size(); i++)
        pr("%d\n", v[i]);
}