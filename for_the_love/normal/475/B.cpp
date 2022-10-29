#include <map>
#include <set>
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
typedef pair<int, int> PI;


const DB eps = 1e-8;
const int N = 22 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[N], t[N];
int v[N][N], n, m, cnt;

void Dfs(int x, int y){
    if (v[x][y]) return;
    v[x][y] = 1;
    cnt++;
    if (s[x] == '>'){
        if (y + 1 < m) Dfs(x, y + 1);
    }else if (y - 1 >= 0) Dfs(x, y- 1);
    if (t[y] == '^'){
        if (x - 1 >= 0) Dfs(x - 1, y);
    }else if (x + 1 < n) Dfs(x + 1, y);
}

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        memset(v, 0, sizeof(v));
        cnt = 0;
        Dfs(i, j);
        if (cnt != n * m){
            puts("NO");
            return 0;
        }
    }
    puts("YES");

}