#include <bits/stdc++.h>

using namespace std;

int n;
char grid[1010][10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", grid[i]);

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (grid[j][i] == '1')
                cnt++;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);

    return 0;
}