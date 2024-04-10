#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,m,x,y,g[505][505],c[505];
char s[505];

void fail() { puts("No"); exit(0); }

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
        ++c[x];
        ++c[y];
    }

    for (int i = 1; i <= n; ++i) {
        if (c[i] == n - 1) { s[i] = 'b'; continue; }
        int can_a = 1, cant_a = 0, can_c = 1, cant_c = 0;
        for (int j = 1; j < i; ++j) {
            if (j != i && c[j] != n - 1) {
                if (g[i][j]) {
                    if (s[j] == 'a') can_c = 0;
                    else can_a = 0;
                } else {
                    if (s[j] == 'a') cant_a = 1;
                    else cant_c = 1;
                }
            }
        }
        if (!can_a && !can_c || cant_a && cant_c) fail();
        if (can_a && !cant_a) s[i] = 'a';
        else if (can_c && !cant_c) s[i] = 'c';
        else fail();
    }
    cout << "Yes\n" << s + 1;


    return 0;
}