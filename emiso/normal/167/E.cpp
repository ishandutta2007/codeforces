#include <bits/stdc++.h>

#define MN 606
long long MOD;

using namespace std;
typedef long long ll;

ll pow_(ll a,ll b) {
    ll ret=1;
    for(;b > 0; b >>= 1){
        if(b % 2)
            ret = (ret * a) % MOD;
        a = (a*a) % MOD;
    }
    return ret;
}

ll inv_mod(ll x) {
    return pow_(x, MOD - 2);
}

vector<vector<long long> > a(MN, vector<long long> (MN));

long long getDet(int n) {
    long long det = 1;
    for(int i = 0; i < n; i++) {
        int pivot = i;
        for(int j = i + 1; j < n; j++)
            if(abs(a[j][i]) > abs(a[pivot][i]))
                pivot = j;

        if(a[pivot][i] == 0)
            return 0;

        if(i != pivot) {
            swap(a[i], a[pivot]);
            det = -det;
        }

        det = (det * a[i][i]) % MOD;
        for(int j = i + 1; j < n; j++)
            a[i][j] = (a[i][j] * inv_mod(a[i][i])) % MOD;

        for(int j = 0; j < n; j++)
            if(i != j && a[j][i])
                for(int k = i + 1; k < n; k++)
                    a[j][k] = (a[j][k] - (a[i][k] * a[j][i])%MOD + MOD) % MOD;
    }

    return (det + MOD) % MOD;
}

vector<int> adj[MN], sources, sinks;
int degIn[MN], degOut[MN], c, b, n, m;
ll ways[MN][MN];

ll calcWays(int a, int b) {
    ll &x = ways[a][b];
    if(x != -1) return x;
    if(a == b) return x = 1;

    x = 0;
    for(int i=0; i<adj[a].size(); i++) {
        x = (x + calcWays(adj[a][i], b)) % MOD;
    }

    return x;
}

int main() {
    scanf("%d %d %lld", &n, &m, &MOD);
    memset(ways, -1, sizeof ways);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &c, &b);
        adj[c].push_back(b);
        degOut[c]++;
        degIn[b]++;
    }

    for(int i=1; i<=n; i++) {
        if(degIn[i] == 0) {
            sources.push_back(i);
        }

        if(degOut[i] == 0) {
            sinks.push_back(i);
        }

        for(int j=1; j<=n; j++) {
            calcWays(i, j);
        }
    }

    int mult = 1;
    for(int i=0, j=0; i<sources.size() && j<sinks.size();) {
        while(sinks[j] < sources[i] && j<sinks.size()) j++;
        if(j == sinks.size()) break;

        if(sinks[j] > sources[i]) i++;
        else if(degIn[i] == 0 && degOut[i] == 0) {
            sources.erase(sources.begin() + i);
            sinks.erase(sinks.begin() + j);
            if((i + j) % 2) mult = -mult;
        }
        else i++;
    }

    for(int i=0; i<sources.size(); i++) {
        for(int j=0; j<sinks.size(); j++) {
            a[i][j] = ways[sources[i]][sinks[j]];
        }
    }

    printf("%lld\n", (mult * getDet(sources.size()) + MOD) % MOD);
    return 0;
}