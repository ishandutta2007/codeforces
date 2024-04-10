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
const int N = 2222;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[N][N];

int n, m, k, ans[N];
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

    for (int i = 1; i <= m; i++){
        for (int j = 2; j <= n; j++){
            if (i - j + 1 > 0 && s[j][i - j + 1] == 'R') ans[i]++;
            if (i + j - 1 <= m && s[j][i + j - 1] == 'L') ans[i]++;
            if (j + j - 1 <= n && s[j + j - 1][i] == 'U') ans[i]++;
        }
        cout << ans[i] << " ";
    }




}