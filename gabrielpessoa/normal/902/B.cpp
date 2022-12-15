#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 1E4+5;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

vi g[SIZE];
int cor[SIZE];
bool vis[SIZE];

int dfs(int p, int c) {
    int resposta = 0;
    if(c != cor[p]) {
        resposta = 1;
        c = cor[p];
    }
    vis[p] = true;
    for(int a : g[p]) {
        if(!vis[a]) {
            resposta += dfs(a, c);
        }
    }
    return resposta;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].push_back(i);
        g[i].push_back(p);
    }
    for(int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        cor[i] = c;        
    }
    printf("%d\n", dfs(1, 0));
    return 0;
}