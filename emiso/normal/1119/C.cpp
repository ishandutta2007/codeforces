#include <bits/stdc++.h>

#define MN 550

using namespace std;
typedef long long ll;

int n, m, ans, a[MN][MN], b[MN][MN];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++)
            sum += (a[i][j] != b[i][j]);
        if(sum % 2) {
            puts("No");
            return 0;
        }
    }

    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += (a[i][j] != b[i][j]);
        if(sum % 2) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");
    return 0;
}