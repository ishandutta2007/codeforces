#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

struct node
{
        int f[3][3];
        node()
        {
                f[0][0] = f[0][1] = f[0][2] = 0;
                f[1][0] = f[1][1] = f[1][2] = 0;
                f[2][0] = f[2][1] = f[2][2] = 0;
        }
        node(int x)
        {
                f[0][0] = f[0][1] = f[0][2] = x;
                f[1][0] = f[1][1] = f[1][2] = x;
                f[2][0] = f[2][1] = f[2][2] = x;
        }
};

int inf = 1e9;

node t[4 * N];

node comb(node A, node B)
{
        node res(inf);
        for(int i = 0; i < 3; i++){
                for(int j = i; j < 3; j++){
                        for(int x = j; x < 3; x++){
                                for(int y = x; y < 3; y++){
                                        res.f[i][y] = min(res.f[i][y], A.f[i][j] + B.f[x][y]);
                                }
                        }
                }
        }
        return res;
}

int n;
int q;
char a[N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x].f[a[l] - 'a'][a[l] - 'a'] = 1;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int g, char c)
{
        if(l == r){
                t[x].f[a[l] - 'a'][a[l] - 'a'] = 0;
                a[l] = c;
                t[x].f[a[l] - 'a'][a[l] - 'a'] = 1;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, c);
        } else {
                upd(x * 2 + 1, m + 1, r, g, c);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        build(1, 1, n);
        for(int i = 1; i <= q; i++){
                int x;
                char c;
                cin >> x >> c;
                upd(1, 1, n, x, c);
                cout << t[1].f[0][2] << "\n";
        }
}