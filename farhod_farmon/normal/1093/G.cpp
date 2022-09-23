#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const ll mod = 998244353;

using namespace std;

int n;
int k;
vector < int > a[N];
int t1[4 * N][1 << 5];
int t2[4 * N][1 << 5];

void build(int x, int l, int r)
{
        if(l == r){
                for(int i = 0; i < (1 << k); i++){
                        int s = 0;
                        for(int j = 0; j < k; j++){
                                if(i & (1 << j)){
                                        s += a[l][j];
                                }
                                else{
                                        s -= a[l][j];
                                }
                        }
                        t1[x][i] = t2[x][i] = s;
                }
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        for(int i = 0; i < (1 << k); i++){
                t1[x][i] = min(t1[x * 2][i], t1[x * 2 + 1][i]);
                t2[x][i] = max(t2[x * 2][i], t2[x * 2 + 1][i]);
        }
}

void upd(int x, int l, int r, int g)
{
        if(l == r){
                 for(int i = 0; i < (1 << k); i++){
                        int s = 0;
                        for(int j = 0; j < k; j++){
                                if(i & (1 << j)){
                                        s += a[l][j];
                                }
                                else{
                                        s -= a[l][j];
                                }
                        }
                        t1[x][i] = t2[x][i] = s;
                }
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g);
        }
        else{
                upd(x * 2 + 1, m + 1, r, g);
        }
        for(int i = 0; i < (1 << k); i++){
                t1[x][i] = min(t1[x * 2][i], t1[x * 2 + 1][i]);
                t2[x][i] = max(t2[x * 2][i], t2[x * 2 + 1][i]);
        }
}

int a1[1 << 5];
int a2[1 << 5];

void get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                for(int i = 0; i < (1 << 5); i++){
                        a1[i] = min(a1[i], t1[x][i]);
                        a2[i] = max(a2[i], t2[x][i]);
                }
                return;
        }
        int m = (l + r) / 2;
        get(x * 2, l, m, tl, min(m, tr));
        get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < k; j++){
                        int x;
                        scanf("%d", &x);
                        a[i].push_back(x);
                }
        }
        build(1, 1, n);
        int q;
        scanf("%d", &q);
        int ms = (1 << k) - 1;
        //cout << t1[1][0] << " " << t1[1][3] << endl;
        //cout << t2[1][0] << " " << t2[1][3] << endl;
        for(int i = 1; i <= q; i++){
                int t;
                scanf("%d", &t);
                if(t == 2){
                        int l, r;
                        scanf("%d%d", &l, &r);
                        for(int j = 0; j < (1 << k); j++){
                                a1[j] = 1e9;
                                a2[j] = -1e9;
                        }
                        get(1, 1, n, l, r);
                        int best = 0;
                        for(int j = 0; j < (1 << k); j++){
                                best = max(best, abs(a1[j] - a2[j]));
                        }
                        printf("%d\n", best);
                }
                else{
                        int x;
                        scanf("%d", &x);
                        for(int j = 0; j < k; j++){
                                int y;
                                scanf("%d", &y);
                                a[x][j] = y;
                        }
                        upd(1, 1, n, x);
                }
        }
}