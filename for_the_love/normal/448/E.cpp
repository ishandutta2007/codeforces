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

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

LL ans[N];
map <LL, int> S;
int cnt, n = 0;
vector <LL> vec[N];
void Dfs(LL x, LL k){
    if (!k || x == 1){
        ans[cnt++] = x;
        return;
    }
    if (S[x]){
        int p = S[x];
        if (vec[p].size() == 2){
            for (int i = 1; i <= k; i++){
                ans[cnt++] = 1;
                if (cnt == 100000) return;
            }
            ans[cnt++] = x;
            return;
        }
        for (int i = 0; i < vec[p].size(); i++){
            Dfs(vec[p][i], k - 1);
            if (cnt == 100000) return;
        }
        return;
    }
    S[x] = ++n;
    for (LL i = 1; i * i <= x; i++)
    if (x % i == 0){
        if (i * i != x) vec[n].PB(x / i);
        vec[n].PB(i);
    }
    sort(vec[n].begin(), vec[n].end());
    Dfs(x, k);
}

int main(){
    LL X, K;
    while (cin >> X >> K){
        cnt = 0;
        Dfs(X, K);
        //printf("%d\n", cnt);
        printf("%I64d", ans[0]);
        for (int i = 1; i < min(100000, cnt); i++) printf(" %I64d", ans[i]); puts("");
    }
}