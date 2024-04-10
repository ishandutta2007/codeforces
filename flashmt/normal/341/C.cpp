#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int BASE = int(1e9) + 7;

long long f[2222][2222], c[2222][2222], fact[2222];
int n, a[2222], seen[2222], cntSeen;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) 
        if (a[i] > 0) seen[a[i]] = 1, cntSeen++;
    
    
    for (int i = 0; i <= n; i++) fact[i] = i ? fact[i - 1] * i % BASE : 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % BASE : 1;
            
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            if (a[i] < 0 && !seen[i]) f[i][j + 1] += f[i - 1][j], f[i][j + 1] %= BASE;
            f[i][j] += f[i - 1][j], f[i][j] %= BASE;
        }
        
    for (int j = 0; j <= n - cntSeen; j++) f[n][j] = f[n][j] * fact[n - cntSeen - j] % BASE;
    
    for (int j = n; j >= 0; j--)
        for (int k = j + 1; k <= n; k++)
        {
            f[n][j] += BASE - f[n][k] * c[k][j] % BASE;
            f[n][j] %= BASE;
        }
        
    cout << f[n][0] << endl;
}