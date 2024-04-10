#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n[3];
vector < int > a[3];

long long get(int a, int b, int c)
{
        long long res = 0;
        res += 1ll * (a - b) * (a - b);
        res += 1ll * (a - c) * (a - c);
        res += 1ll * (c - b) * (c - b);
        return res;
}

void solve()
{
        cin >> n[0] >> n[1] >> n[2];

        for(int i = 0; i < 3; i++){
                a[i].resize(n[i]);
                for(int j = 0; j < n[i]; j++){
                        cin >> a[i][j];
                }
                sort(a[i].begin(), a[i].end());
        }

        long long res = (long long)4e18;
        vector < int > ord = {0, 1, 2};
        do{
                int x = ord[0], y = ord[1], z = ord[2];
                for(int i = 0, h = 0, j = 0; j < n[y]; j++){
                        while(i + 1 < n[x] && a[x][i + 1] <= a[y][j]) i += 1;
                        while(h + 1 < n[z] && a[z][h] < a[y][j]) h += 1;
                        res = min(res, get(a[x][i], a[y][j], a[z][h]));
                }

        }while(next_permutation(ord.begin(), ord.end()));

        cout << res << "\n";
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);


        int T;
        cin >> T;
        while(T--) solve();
}