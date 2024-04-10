#include <bits/stdc++.h>
using namespace std;
int n, a[2005][2005];
int main() {
    ios :: sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i += 4)
        for(int j = 0; j < n; j += 4)
            for(int k = 0; k < 4; k++)
                for(int l = 0; l < 4; l++)
                    a[i | k][j | l] = i * n + (j << 2) + (k << 2) + l;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " \n"[j == n - 1];
    }
    return 0;
}