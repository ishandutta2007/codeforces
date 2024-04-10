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
#include <unordered_map>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

unordered_map <int, int > S[21];
unordered_map <int, int > :: iterator it;

int n, m, a[100], b[100], q[100];

vector <int> vec[100];

int get(int x){
    int cnt = 0, f = 0;
    for (int i = 0; i < n; i++)
    if (x >> i & 1) f = 1;
    else{
        if (f) cnt++;
        f = 0;
    }
    if (f) cnt++;
    return cnt;
}

char ans[100][100];

int p;
int t[5];

void Dfs(int x, int y, int z){ //yz
    for (int i = 0; i < vec[b[x]].size(); i++){
        int Y = vec[b[x]][i];
        int tmp = z, Z = 0, flag = 0;
        for (int j = 0; j < n; j++){
            t[j] = tmp % p;
            if ((Y >> j & 1) && !(y >> j & 1)) t[j]++;
            if (t[j] == p || (m - x) / 2 < a[j] - t[j]){
                flag = 1;
                break;
            }
            Z += t[j] * q[j];
            tmp /= p;
        }
        if (flag) continue;
        S[x + 1][Y + Z * 100] = y + z * 100;
    }
}

void Gao(int x, int y, int z){
    if (x == 0) return;
    for (int i = 0; i < n; i++)
    if (y >> i & 1) ans[i][x] = '*'; else ans[i][x] = '.';
    Gao(x - 1, S[x][y + z * 100] % 100, S[x][y + z * 100] / 100);
}

int main(){
    scanf("%d%d", &n, &m);
    p = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        p = max(p, a[i]);
    }
    p++;
    q[0] = 1;
    for (int i = 1; i <= n; i++) q[i] = q[i - 1] * p;

    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0; i < 1 << n; i++)
        vec[get(i)].push_back(i);

    S[0][0] = 0;

    for (int i = 0; i < m; i++)
    for (it = S[i].begin(); it != S[i].end(); it++)
        Dfs(i, it->first % 100, it->first / 100);

    int t = 0;
    for (int i = 0; i < n; i++)
        t += a[i] * q[i];

    for (it = S[m].begin(); it != S[m].end(); it++)
    if (it->first / 100 == t){
        //printf("!!!!");
        Gao(m, it->first % 100, it->first / 100);
        for (int i = 0; i < n; i++){
            for (int j = 1; j <= m; j++)
                printf("%c", ans[i][j]);
            puts("");
        }
        return 0;
    }
}