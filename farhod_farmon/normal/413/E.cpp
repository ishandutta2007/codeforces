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

int n, m, d[N], r[N], l[N];
int p[N + N];
char c[3][N];

int get(int x)
{
    int cnt = 0;
    if(c[0][x] == 'X')
        cnt += 1;
    if(c[1][x] == 'X')
        cnt += 2;
    return cnt;
}

int p_get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = p_get(p[x]);
}

void comb(int x, int y)
{
    x = p_get(x);
    y = p_get(y);
    if(x != y)
        p[x] = y;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int pre = -1;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            p[i * n + j] = i * n + j;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            if(c[i][j] == 'X')
                continue;
            if(c[i][j + 1] == '.')
                comb(i * n + j, i * n + j + 1);
            if(c[i + 1][j] == '.')
                comb(i * n + j, (i + 1) * n + j);
        }
    }
    for(int i = 0; i < n; i++){
        int g = get(i);
        l[i] = pre;
        if(g == 3 || g == 0)
            continue;
        if(pre != -1){
            int pg = get(pre % n);
            d[i] = d[pre % n];
            if(pg != g)
                d[i]++;
        }
        l[i] = i;
        pre = i;
        if(g == 1)
            pre += n,
            l[i] += n;
    }
    r[n] = n + n - 1;
    for(int i = n - 1; i >= 0; i--){
        int g = get(i);
        r[i] = r[i + 1];
        if(g == 1 || g == 2)
            r[i] = i;
        if(g == 1)
            r[i] += n;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        if(p_get(x) != p_get(y)){
            cout << -1 << endl;
            continue;
        }
        int hx = x / n,
            hy = y / n;
        x %= n;
        y %= n;
        if(x > y)
            swap(x, y),
            swap(hx, hy);
        int ans = y - x;
        if(r[x] % n >= y || l[y] % n <= x){
            if(hx != hy)
                ans++;
            cout << ans << endl;
            continue;
        }
        if(hx != r[x] / n)
            ans++;
        if(hy != l[y] / n)
            ans++;
        cout << ans + d[l[y] % n] - d[r[x] % n] << endl;
    }
}