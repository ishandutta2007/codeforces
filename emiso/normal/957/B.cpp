#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
char a[55][55];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    int f = 1;
    for(int i = 0; i < n; i++) {
        vector<int> col;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#') col.push_back(j);
        }

        for(int k = 0; k < n; k++) {
            int sum = 0;
            for(int c : col) {
                sum += (a[k][c] == '#');
            }
            if(sum != 0 && sum != col.size()) f = 0;
        }
    }

    printf("%s\n", f ? "Yes" : "No");
    return 0;
}