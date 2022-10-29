#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[N], t[N];
int f[N], g[N], sum[N][26];

bool Find(char ch, int i, int j){
    return (sum[j][ch - 'a'] - sum[i - 1][ch - 'a']) > 0;
}
int main(){
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    int p = 1;
    for (int i = 1; i <= m; i++)
    for (int j = 'a'; j <= 'z'; j++)
        sum[i][j - 'a'] = sum[i - 1][j - 'a'] + (t[i] == j);
    for (int i = 1; i <= n; i++){
        if (p <= m && s[i] == t[p]) p++;
        f[i] = p - 1;
    }
    p = m;
    for (int i = n; i >= 1; i--){
        if (p > 0 && s[i] == t[p]) p--;
        g[i] = p + 1;
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    if (f[i] < g[i] || !Find(s[i], g[i], f[i])) flag = 1;
    if (flag) puts("No"); else puts("Yes");
}