#include<bits/stdc++.h>
using namespace std;

const long long Mod = 998244353;

int n, u, v;
vector<int> e[200001];
bool chk[200001];
long long memo[200001];

long long g(long long k) {
    if(k==1) return 1;
    if(memo[k]) return memo[k];
    return memo[k] = k * g(k-1) % Mod;
}

long long f(int k) {
    chk[k] = true;
    long long ans = 1;

    for(int i=0; i<e[k].size(); i++) {
        if(chk[e[k][i]]) continue;

        ans *= f(e[k][i]);
        ans %= Mod;
    }

    ans *= g(e[k].size());
    ans %= Mod;

    return ans;
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n-1; i++) {
        scanf("%d%d", &u, &v);

        e[u].push_back(v);
        e[v].push_back(u);
    }

    long long ans = f(1) * n % Mod;
    printf("%lld", ans);
}