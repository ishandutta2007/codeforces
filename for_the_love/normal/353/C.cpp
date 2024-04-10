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
const int N = 111111;
const int INF = 1e9 + 7;
int n, f[N][2], a[N];
string s;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cin >> s;
    f[n][0] = f[n][1] = -INF;
    f[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    if (s[i] == '1'){
        f[i][0] = max(f[i + 1][1], f[i + 1][0] + a[i]);
        f[i][1] = f[i + 1][1] + a[i];
    }else{
        f[i][0] = f[i + 1][0] + a[i];
        f[i][1] = f[i + 1][1];
    }
    printf("%d\n", max(f[0][0], f[0][1]));
}