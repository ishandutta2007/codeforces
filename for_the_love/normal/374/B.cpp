#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111111;

long long g[N], f[N], a[N];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    g[0] = 1;
    for (int i = 1; i <= n; i++){
        if (a[i] == 9) f[i] = f[i - 1] + 1; else f[i] = f[i - 1];
        g[i] = g[i - 1];
        if (i > 1 && a[i] + a[i - 1] == 9){
            if (f[i - 2] + 1 > f[i]){
                f[i] = f[i - 2] + 1;
                g[i] = g[i - 2];
            }else if (f[i - 2] + 1 == f[i]) g[i] += g[i - 2];
        }
    }
    cout << g[n] << endl;
}