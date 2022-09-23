#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;
int w;
int k;
int a[N];
int t[N];
pair < int, int > p[4 * MX + 44];

void upd(int x, int l, int r, int g, int y)
{
    if(l == r){
        p[x].fi += y;
        p[x].se += l * y;
        return;
    }
    int m = (l + r) / 2;
    if(g <= m)
        upd(x * 2, l, m, g, y);
    else
        upd(x * 2 + 1, m + 1, r, g, y);
    p[x].fi = p[x * 2].fi + p[x * 2 + 1].fi;
    p[x].se = p[x * 2].se + p[x * 2 + 1].se;
}

int get(int x, int l, int r, int need)
{
    if(l == r)
        return l * min(need, p[x].fi);
    int m = (l + r) / 2;
    if(p[x * 2 + 1].fi <= need)
        return get(x * 2, l, m, need - p[x * 2 + 1].fi) + p[x * 2 + 1].se;
    else
        return get(x * 2 + 1, m + 1, r, need);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> w >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    int j = n;
    int s = 0;
    int ans = 0;
    for(int i = n; i >= 1; i--){
        s += t[i];
        upd(1, 1, MX, t[i] / 2, 1);
        while(s - get(1, 1, MX, w) > k){
            upd(1, 1, MX, t[j] / 2, -1);
            s -= t[j];
            j--;
        }
        ans = max(ans, a[j] - a[i - 1]);
    }
    cout << ans << endl;
}