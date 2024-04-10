#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int v[22][22], a[22], b[22], c[22];
vector <int> x[10], y[10], z[10];
bool Dfs(int k, int lend){
    if (v[k][lend] != -1) return v[k][lend];
    v[k][lend] = 0;
    if (k == 0) return 0;
    int t = a[k], p = 0;
    if (t < lend) p = 1;
    t = (t - lend + 100) % 10;
    for (int i = 0; i < (int)x[t].size(); i++){
        b[k] = x[t][i];
        c[k] = y[t][i];
        if (Dfs(k - 1, p + z[t][i])){
            v[k][lend] = 1;
            return 1;
        }
    }
    return v[k][lend];
}

long long ans[7];
int main(){
    int cas;
    scanf("%d", &cas);
    for (int i = 0; i <= 6; i++)
    for (int j = 0; j + i <= 6; j++)
        x[(i * 4 + j * 7) % 10].push_back(i), y[(i * 4 + j * 7) % 10].push_back(j), z[(i * 4 + j * 7) % 10].push_back((i * 4 + j * 7) / 10);
    while (cas--){
        long long num;
        cin >> num;
        int l = 0;
        while (num){
            b[++l] = num % 10;
            num /= 10;
        }
        for (int i = 1; i <= l; i++) a[i] = b[l - i + 1];
        memset(v, -1, sizeof(v));
        v[0][0] = 1;
        for (int i = 0; i < 6; i++) ans[i] = 0;
        if (!Dfs(l, 0)) puts("-1");
        else{
            for (int i = 0; i < l; i++){
                for (int j = 0; j < 6; j++) ans[j] *= 10;
                for (int j = 0; j < b[i + 1]; j++) ans[j] += 4;
                for (int j = b[i + 1]; j < b[i + 1] + c[i + 1]; j++) ans[j] += 7;
                for (int j = b[i + 1] + c[i + 1]; j < 6; j++) ans[j] += 0;
            }
            for (int i = 0; i < 6; i++){
                cout << ans[i] << " ";
            }
            puts("");
        }
    }
}