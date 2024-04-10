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

const int INF = 1e9 + 7;

int n, m, a[105], b[105], p[105], v[105], f[105];
string str;


int work1(){
    int ret = 0;
    for (int i = 1; i <= n; i++)
    if (p[i] == 1){
        int mn = INF, node;
        for (int j = 1; j <= m; j++)
        if (!v[j] && b[j] > a[i] && b[j] < mn){
            mn = b[j];
            node = j;
        }
        if (mn == INF) return 0;
        v[node] = 1;
    }
    for (int i = 1; i <= n; i++)
    if (p[i] == 2){
        int found = 0;
        for (int j = 1; j <= m; j++)
        if (!v[j] && b[j] >= a[i]){
            found = 1;
            ret += b[j] - a[i];
            v[j] = 1;
            break;
        }
        if (!found) return 0;
    }
    for (int i = 1; i <= m; i++)
    if (!v[i]) ret += b[i];
    return ret;
}
int work2(){
    int ret = 0;
    sort(b + 1, b + m + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    if (p[i] == 2) a[++cnt] = a[i];
    n = cnt;
    //sort(a + 1, a + n + 1);
    memset(f, 0x7f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = i; j >= 1; j--)
        f[j] = min(f[j], f[j - 1] + a[i]);
    int sum = 0;
    for (int i = m; i >= 1; i--){
        sum += b[i];
        ret = max(ret, sum - f[m - i + 1]);
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> str >> a[i];
        if (str == "DEF") p[i] = 1; else p[i] = 2;
    }
    for (int i = 1; i <= m; i++) cin >> b[i];
    cout << max(work2(), work1()) << endl;
}