#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

int n;
int m;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                int res = 0, S = x;
                for(int j = 1; j <= 100; j++){
                        int g = min((m - S) / j, a[j]);
                        res += g;
                        S += g * j;
                }
                cout << i - res - 1 << " ";
                a[x] += 1;
        }
}