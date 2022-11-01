#include <bits/stdc++.h>

#define MN 110
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define X first
#define Y second

using namespace std;
typedef long long ll;

int n, k, ans, ax, ay, possib[MN][MN];
char line[MN], grid[MN][MN];

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%s", line);
        for(int j=0; j<n; j++) {
            grid[i][j] = line[j];
        }
    }

    for(int i = 0; i + k <= n; i++) {
        for(int j = 0; j < n; j++) {
            int flag = 1;
            for(int l = 0; l < k && flag; l++) {
                if(grid[i+l][j] == '#') flag = 0;
            }

            for(int l = 0; l < k && flag; l++) {
                possib[i+l][j]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j + k <= n; j++) {
            int flag = 1;
            for(int l = 0; l < k && flag; l++) {
                if(grid[i][j+l] == '#') flag = 0;
            }

            for(int l = 0; l < k && flag; l++) {
                possib[i][j+l]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(possib[i][j] > ans) {
                ans = possib[i][j];
                ax = i; ay = j;
            }
        }
    }

    printf("%d %d\n", ax + 1, ay + 1);
    return 0;
}