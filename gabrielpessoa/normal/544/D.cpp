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

const int SIZE  = 3005;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

int d[SIZE][SIZE];
vi g[SIZE];
queue<int> q;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(d, 63, sizeof(d));
    for(int i = 1; i <= n; i++) {
        d[i][i] = 0;
        q.push(i);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int a : g[v]) {
                if(d[i][v] + 1 < d[i][a]) {
                    d[i][a] = d[i][v] + 1;
                    q.push(a);
                }
            }
        }
    }
    int s1, t1, l1, s2, t2, l2;
    scanf("%d %d %d %d %d %d", &s1, &t1, &l1, &s2, &t2, &l2);
    if(d[s1][t1] > l1 || d[s2][t2] > l2) {
        printf("-1\n");
        return 0;
    }
    int resposta = m - d[s1][t1] - d[s2][t2];
    //printf("resposta agora eh %d\n", resposta);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][i] + d[i][j] + d[j][t2] <= l2) {
                resposta = max(resposta, m - d[s1][i] - d[j][t1] - d[s2][i] - d[j][t2] - d[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[s1][i] + d[i][j] + d[j][t1] <= l1 && d[s2][j] + d[i][j] + d[i][t2] <= l2) {
                resposta = max(resposta, m - d[s1][i] - d[j][t1] - d[s2][j] - d[i][t2] - d[i][j]);
            }
        }
    }
    printf("%d\n", resposta);
    return 0;
}