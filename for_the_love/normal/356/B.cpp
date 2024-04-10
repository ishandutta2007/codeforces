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
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int c1[26][N], c2[26][N];
char s[N], t[N];
LL n, m;

LL gcd(LL a, LL b){if (!b) return a; return gcd(b, a % b);}


int main(){
    cin >> n >> m;
    scanf("%s", s); scanf("%s", t);
    LL ls = strlen(s), lt = strlen(t);
    LL g = gcd(ls, lt);
    for (int i = 0; i < ls; i++) c1[s[i] - 'a'][i % g]++;
    for (int i = 0; i < lt; i++) c2[t[i] - 'a'][i % g]++;
    LL ans = 0;
    for (int i = 0; i < 26; i++)
    for (int j = 0; j < g; j++)
        ans += (LL)c1[i][j] * c2[i][j];

    cout << n * ls - ans * (n / (lt / g)) << endl;


}