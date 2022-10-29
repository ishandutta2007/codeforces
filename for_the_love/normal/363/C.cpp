//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

char s[N], t[N];
int v[N];

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%s", s + 1);
    int n = strlen(s + 1), m = 1, cnt = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == t[cnt] && m == 2) continue;
        if (s[i] == t[cnt]) m++; else m = 1;
        t[++cnt] = s[i];
    }
    n = cnt;
    for (int i = 3; i < n; i++)
    if (t[i] == t[i + 1] && t[i - 1] == t[i - 2] && !v[i - 2]) v[i] = 1;
    for (int i = 1; i <= n; i++)
    if (!v[i]) printf("%c", t[i]);
}