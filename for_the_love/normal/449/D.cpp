#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const int N = 1e6 + 7;
const int M = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const DB eps = 1e-6;


LL pw[N], c[N], s[N];

int main(){
    int n, x;
    scanf("%d", &n);
    pw[0] = 1;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        c[x]++;
        pw[i] = pw[i - 1] * 2 % MOD;
    }

    LL ans = 0;
    for (int j = 0; j < 20; j++)
    for (int i = 1000000; i > 0; i--)
    if (i >> j & 1){
        c[i ^ (1 << j)] += c[i];
        s[i] ^= 1;
    }

    for (int i = 1; i <= 1000000; i++){
        if (s[i]) ans = (ans + pw[c[i]] - 1 + MOD) % MOD;
        else ans = (ans - pw[c[i]] + 1 + MOD) % MOD;
    }

    cout << (pw[n] - 1 - ans + MOD) % MOD << endl;
}