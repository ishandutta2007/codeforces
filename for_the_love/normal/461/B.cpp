#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


LL dp[N][2];
int c[N];
vector <int> e[N];


void ext_gcd(LL a, LL b, LL &d, LL &x, LL &y){
    if (!b){d = a, x = 1, y = 0;}
    else{ext_gcd(b, a % b, d, y, x); y-= x * (a / b);}
}
LL inv(LL a, LL c){
    LL d, x, y;
    ext_gcd(a, c, d, x, y);
    return (x + c) % c;
}

void Dfs(int x, int par){
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par) Dfs(e[x][i], x);
    if (c[x]){
        LL t = 1;
        for (int i = 0; i < e[x].size(); i++)
        if (e[x][i] != par){
            int y = e[x][i];
            t = (t * (dp[y][0] + dp[y][1])) % MOD;
        }
        dp[x][0] = 0; dp[x][1] = t;
    }else{
        LL t = 1;
        dp[x][0] = 1;
        for (int i = 0; i < e[x].size(); i++)
        if (e[x][i] != par){
            int y = e[x][i];
            dp[x][0] = (dp[x][0] * (dp[y][0] + dp[y][1])) % MOD;
            t = (t * (dp[y][0] + dp[y][1])) % MOD;
        }
        dp[x][1] = 0;
        for (int i = 0; i < e[x].size(); i++)
        if (e[x][i] != par){
            int y = e[x][i];
            dp[x][1] = (dp[x][1] + (t * inv((dp[y][0] + dp[y][1]) % MOD, MOD) % MOD * dp[y][1] % MOD)) % MOD;
        }
    }
}


int main(){
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        scanf("%d", &x);
        e[x].PB(i); e[i].PB(x);
    }
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    Dfs(0, -1);
    printf("%d\n", (int)dp[0][1]);
}