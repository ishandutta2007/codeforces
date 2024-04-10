#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
const int INF = 1e9 +7;

typedef long long LL;
char s[N][N];
int n, G[N], D[N], v[N];

void Add(int x, int y){s[x][y] = s[y][x] = 'Y';}
void Build(int cnt, int t){
    if (!t){
        while (cnt--){
            n++;
            Add(1, n);
            for (int i = 0; i < 10; i++){
                Add(n, n + 1);
                n++;
            }
            Add(n, 2);
        }
        return;
    }
    n += 10;
    for (int i = 1; i <= 10; i++)
        Add(1, n - i + 1);
    for (int i = 0; i < t - 1; i++){
        n += 10;
        for (int x = 1; x <= 10; x++)
        for (int y = 1; y <= 10; y++)
            Add(n - 20 + x, n - 10 + y);
    }
    for (int x = 1; x <= 10; x++)
    for (int y = 1; y <= cnt; y++)
        Add(n - 10 + x, n + y);
    for (int y = 1; y <= cnt; y++)
        Add(n + y, n + cnt + 1);
    n += cnt + 1;
    for (int i = t; i < 9; i++){
        Add(n, n + 1);
        n++;
    }
    Add(n, 2);
}

int main(){
    int K;
    for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
        s[i][j] = s[j][i] = 'N';
    cin >> K;
    n = 2;
    int t = 0;
    for (int i = 1; i <= K; i *= 10){
        int cnt = K % ((LL)i * 10) / i;
        Build(cnt, t);
        t++;
    }
    cout << n << endl;
    int tot = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%c", s[i][j]);
            //if (i < j && s[i][j] == 'Y') printf("%d %d\n", i, j);
        }
        puts("");
    }
    //cout << tot << endl;
//    memset(D, 0x7f, sizeof(D));
//    D[1] = 0; G[1] = 1;
//    for (int i = 1; i <= n; i++){
//        int node, mn = INF;
//        for (int j = 1; j <= n; j++)
//        if (!v[j] && D[j] < mn){
//            mn = D[j];
//            node = j;
//        }
//        v[node] = 1;
//        for (int j = 1; j <= n; j++)
//        if (s[node][j] == 'Y' && D[node] + 1 < D[j]){
//            D[j] = D[node] + (s[node][j] == 'Y');
//            G[j] = G[node];
//        }else if (s[node][j] == 'Y' && D[node] + 1 == D[j]) G[j] += G[node];
//    }
//    cout << G[2] << endl;
}