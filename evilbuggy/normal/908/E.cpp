#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;
const int maxn = 1005;

ll bell[maxn], ncr[maxn][maxn];

void pre(){
    memset(ncr, 0, sizeof(ncr));
    ncr[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++){
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%mod;
        }
    }
    bell[0] = 1;
    for(int i = 1; i < maxn; i++){
        bell[i] = 0;
        for(int k = 0; k <= i-1; k++){
            bell[i] += (ncr[i-1][k]*bell[k])%mod;
        }
        bell[i] %= mod;
    }
}

int g[maxn][maxn];
int p[maxn], sz[maxn];

int find(int v){
    return (p[v] == v)?v:(find(p[v]));
}

void combine(int u, int v){
    u = find(u); v = find(v);
    if(u == v)return;
    if(sz[u] < sz[v])swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
}

int main(){
    pre();
    int m, n;
    cin>>m>>n;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                if(s[j] == s[k]){
                    g[j][k]++;
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            if(g[i][j] == n)combine(i, j);
        }
    }
    set<int> arr;
    for(int i = 0; i < m; i++){
        arr.insert(find(i));
    }
    ll ans = 1;
    for(auto x : arr){
        (ans *= bell[sz[x]]) %= mod;
    }
    cout<<ans<<endl;
}