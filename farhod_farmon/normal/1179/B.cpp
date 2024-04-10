#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

void solve(int l, int r, int m)
{
        if(l > r){
                return;
        }
        if(l == r){
                for(int i = 2, j = m; i <= j; i++, j--){
                        printf("%d %d\n", l, j);
                        if(i < j){
                                printf("%d %d\n", l, i);
                        }
                }
                return;
        }
        for(int i = 1; i <= m; i++){
                printf("%d %d\n", r, m - i + 1);
                if(i < m){
                        printf("%d %d\n", l, i + 1);
                }
        }
        if(l + 1 < r){
                printf("%d %d\n", l + 1, 1);
        }
        solve(l + 1, r - 1, m);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d %d\n", 1, 1);
        solve(1, n, m);
}