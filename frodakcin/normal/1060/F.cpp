#include <iostream>
#include <cstdio>

#include <vector>
#include <iomanip>

using namespace std;

#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ld> vld;

#define tld(x) static_cast<ld>(x)

const int MAXN = 50 + 10;

int N;
vi adj[MAXN];
vld dp[MAXN];
ll bin[MAXN][MAXN];

vld incr(const vld& a) {
    int s = a.size();
    vld ret(s + 1, tld(0));
    for(int i = 0;i <= s;i++) {
        ld p = tld(1)/(s);
        for(int j = 0;j < s;ret[i] += p * a[max(i - 1, j++)]) if(j == i) p *= 0.5;
    }
    return ret;
}

vld comb(const vld& a, const vld& b) {
    vld ret(a.size() + b.size() - 1, tld(0));
    for(int i = 0;i < a.size();i++) for(int j = 0;j < b.size();j++) {
        ret[i + j] += (a[i] * b[j]) * (tld(bin[a.size() - 1][i]) * bin[b.size() - 1][j]/tld(bin[a.size() + b.size() - 2][i + j]));
    }
    return ret;
}

void solve(int n, int p = -1) {
    dp[n].assign(1, tld(1));
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i] == p) continue;
        solve(adj[n][i], n);
        
        dp[n] = comb(dp[n], incr(dp[adj[n][i]]));
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0, j;i <= N;i++) for(bin[i][0] = bin[i][i] = 1, j = 1;j < i;j++) bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
    for(int i = 0, a, b;i < N - 1;i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1;i <= N;i++) {
        solve(i);
        //printf("%.7Lg\n", dp[i][0]);
        cout << setprecision(7) << dp[i][0] << endl;
    }
    return 0;
}