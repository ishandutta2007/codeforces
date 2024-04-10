//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

int v[1 + MAXN];
long long dp[1 + MAXN];

int main() {
    int n;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = 20 + dp[i - 1];
        while (a <= i && v[a] < v[i] - 89)
            a++;
        dp[i] = min(dp[i], dp[a - 1] + 50);
        while (b <= i && v[b] < v[i] - 1439)
            b++;
        dp[i] = min(dp[i], dp[b - 1] + 120);
        cout << dp[i] - dp[i - 1] << "\n";
    }
    return 0;
}