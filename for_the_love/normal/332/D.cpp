#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, e[2005][2005]; double c[2005][2005];
long long ans;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++){
        scanf("%d", &e[i][j]);
        e[j][i] = e[i][j];
    }
    for (int i = 0; i <= n; i++) c[i][0] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    double d = 0, u = 0;
    for (int i = 1; i <= n; i++){
        long long cnt = 0;
        double sum = 0;
        for (int j = 1; j <= n; j++)
        if (i != j && e[i][j] != -1){
            cnt++;
            sum += e[i][j];
        }
        if (cnt >= k){
            u += sum / cnt * k * c[cnt][k];
            d += c[cnt][k];
        }
    }
    cout << (long long)(u / d) << endl;

}