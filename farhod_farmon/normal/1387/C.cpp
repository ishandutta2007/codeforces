#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150;

using namespace std;

#define ull __int128
int G;
int g, n, m;
int t[N][2];
int link[N], par[N], parc[N];
int dead[N];
ull d[N][N][N];
ull f[N], nf[N];
ull inf = 1;
ull A[N];
vector < vector < int > > v[N];

int go(int v, int c);
int get_link(int v)
{
        if(link[v] == -1){
                if(v == 0 || par[v] == 0) link[v] = 0;
                else link[v] = go(get_link(par[v]), parc[v]);
        }
        return link[v];
}

int go(int v, int c)
{
        if(t[v][c] == -1){
                t[v][c] = (v == 0 ? 0 : go(get_link(v), c));
        }
        return t[v][c];
}

void upd(ull &x, ull y)
{
        x = min(x, y);
}

void print(ull x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        //cout << inf << endl;
        for(int i = 0; i < 120; i++) inf += inf;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        for(int h = 0; h < N; h++){
                                d[i][j][h] = inf;
                        }
                }
                t[i][0] = t[i][1] = link[i] = -1;
        }

        cin >> g >> n >> m;
        //if(n != g - 2) return 0;
        for(int i = 1; i <= n; i++){
                int x, k;
                cin >> x >> k;
                v[x].push_back(vector < int > (k));
                for(int j = 0; j < k; j++){
                        cin >> v[x].back()[j];
                }
        }
        for(int i = 1; i <= m; i++){
                int k;
                cin >> k;
                int cur = 0;
                for(int j = 0; j < k; j++){
                        int x;
                        cin >> x;
                        if(t[cur][x] == -1){
                                t[cur][x] = ++G;
                                par[G] = cur;
                                parc[G] = x;
                        }
                        cur = t[cur][x];
                }
                dead[cur] = true;
        }

        G += 1;

        for(int i = 0; i < G; i++){
            for(int j = 0; j < 2; j++){
                if(t[i][j] != -1){
                    dead[t[i][j]] |= dead[i];
                }
            }
        }

        for(int i = 0; i < G; i++){
                go(i, 0);
                go(i, 1);
        }

        for(int i = 0; i < G; i++){
                for(int j = i; j > 0; j = get_link(j)){
                        dead[i] |= dead[j];
                }
        }

        for(int i = 0; i < G; i++){
                if(dead[i]) continue;
                if(!dead[t[i][0]]) d[0][i][t[i][0]] = 1;
                if(!dead[t[i][1]]) d[1][i][t[i][1]] = 1;
        }
        A[0] = A[1] = 1;
        for(int i = 2; i < g; i++) A[i] = inf;

        while(true){
                bool done = true;
                for(int i = 2; i < g; i++){
                        for(int j = 0; j < G; j++){
                                if(dead[j]) continue;
                                for(auto &P: v[i]){
                                        for(int h = 0; h < G; h++){
                                                f[h] = inf;
                                        }
                                        f[j] = 0;
                                        for(int x: P){
                                                for(int h = 0; h < G; h++){
                                                        nf[h] = inf;
                                                }
                                                for(int h = 0; h < G; h++) if(f[h] != inf){
                                                        if(dead[h]) continue;
                                                        for(int k = 0; k < G; k++){
                                                                if(dead[k]) continue;
                                                                upd(nf[k], f[h] + d[x][h][k]);
                                                        }
                                                }
                                                for(int h = 0; h < G; h++){
                                                        f[h] = nf[h];
                                                }
                                        }
                                        for(int h = 0; h < G; h++){
                                                if(f[h] < d[i][j][h]){
                                                        d[i][j][h] = f[h];
                                                        done = false;
                                                }
                                        }
                                }
                        }
                        /*
                        if(A[i] == inf){
                                A[i] = 0;
                                for(auto &P: v[i]){
                                        for(int x: P){
                                                A[i] += A[x];
                                                if(A[x] == inf) break;
                                        }
                                }
                                A[i] = min(A[i], inf);
                        }
                        */
                }
                if(done) break;
        }
        ull shit = 1;
        for(int i = 0; i < 63; i++) shit += shit;
        for(int i = 2; i < g; i++){
                ull res = inf;
                for(int j = 0; j < G; j++){
                        if(dead[j]) continue;
                        res = min(res, d[i][0][j]);
                }
                if(res >= shit) printf("YES\n");
                else{
                    printf("NO ");
                    print(res);
                    printf("\n");
                }
        }
}