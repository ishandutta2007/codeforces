#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

#define pb push_back
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1e6 + 100;
const int MOD = 1e9 + 7;

int N, a[MAXN];
vi adj[MAXN];
ll s[MAXN], k[MAXN], dp[MAXN];

void dfs(int n, int p = -1) {
    s[n] = a[n];
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        dfs(adj[n][i], n);
        s[n] += s[adj[n][i]];
    }
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%d", &N);
    for(int i = 1;i <= N;i++) scanf("%d", a + i);
    for(int i = 2;i <= N;i++) {
        int b;
        scanf("%d", &b);
        adj[b].pb(i);
        adj[i].pb(b);
    }
    
    dfs(1);
    
    for(int i = 0;i <= N;i++) k[i] = 0;
    for(int i = N;i >= 1;i--) if((s[i] = s[1] / gcd(s[i], s[1])) <= N) k[s[i]]++;
    
    for(int i = N;i >= 1;i--) for(int j = 2*i;j <= N;j += i) k[j] += k[i];
    
    for(int i = 0;i <= N;i++) dp[i] = 0;
    for(int i = N, j;i >= 1;i--) if(k[i] == i) for(j = 2 * i, dp[i] += 1;j <= N;j += i) dp[i] += dp[j];
    
    printf("%d\n", static_cast<int> (dp[1]%MOD));
    
    return 0;
}