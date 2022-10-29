#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;
typedef pair<string, string> PS;
const DB eps = 1e-6;
const int N = 1e3 +7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

vector <PI> ans;
int b[N][N];
int main(){
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        int cnt = m;
        for (int j = 1; j <= n; j++)
        if (i != j && !b[j][i]){
            ans.PB(MP(i, j));
            b[i][j] = 1;
            cnt--;
            if (!cnt) break;
        }
        if (cnt){
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
}