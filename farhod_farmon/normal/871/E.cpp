#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 30300;
const int Q = 220;

using namespace std;

int n, k;
int p[N];
int bitch[N];
int batya[N];
vector < int > d[Q];
vector < vector < int > > lev;

void wa()
{
        cout << -1 << "\n";
        exit(0);
}

void make(int x, int y, int i, int j)
{
        if(d[i][y] != d[j][x]) wa();
        for(int z = 0; z <= n; z++) bitch[z] = -1;
        for(int z = 1; z <= n; z++){
                if(d[i][z] + d[j][z] == d[i][y]){
                        if(bitch[d[i][z]] != -1) wa();
                        bitch[d[i][z]] = z;
                }
        }
        int last = 0;
        for(int i = 1; i <= n; i++) if(bitch[i] != -1) last = i;

        for(int h = 1; h <= last; h++){
                int x = bitch[h - 1], y = bitch[h];
                if(x == -1) wa();

                p[y] = x;
        }
}

int inv[Q][N];
long long A[Q][N];
map < long long, int > D;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long get(int x, int dif)
{
        long long res = 0;
        for(int i = 1; i <= k; i++){
                if(inv[i][x] + dif < 0) return (long long) rng();
                res ^= A[i][inv[i][x] + dif];
        }
        return res;
}

void build(vector < int > v)
{
        D.clear();
        for(int x: v){
                D[get(x, 0)] = x;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        lev.resize(n);
        for(int i = 1; i <= k; i++){
                d[i].resize(n + 1);
                for(int j = 1, x; j <= n; j++){
                        cin >> x;
                        d[i][j] = x;
                        if(i == 1)lev[x].push_back(j);

                        inv[i][j] = x;

                        A[i][j - 1] = (long long)rng();

                        if(!x){
                                if(batya[i]) wa();
                                batya[i] = j;
                        }

                }
                if(!batya[i]) wa();
        }
        int root = lev[0][0];

        for(int i = 2; i <= k; i++){
                int x = batya[i];
                make(root, x, 1, i);
        }

        for(int i = 1; i < n; i++){
                if(lev[i].empty()) break;

                build(lev[i - 1]);

                for(int x: lev[i]){
                        if(p[x]) continue;
                        long long hsh = get(x, -1);
                        if(D.find(hsh) == D.end()){
                                wa();
                        }
                        p[x] = D[hsh];
                }
        }

        for(int i = 1; i <= n; i++){
                if(i != root && !p[i]) wa();
        }
        for(int i = 1; i <= n; i++) if(root != i) cout << i << " " << p[i] << "\n";
}