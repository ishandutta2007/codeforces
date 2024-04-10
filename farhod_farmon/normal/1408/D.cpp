#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000110;

using namespace std;

int n, m;
int a[N], b[N], c[N], d[N];

int shit[Q];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        for(int i = 1; i <= m; i++) cin >> c[i] >> d[i];

        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        int X = c[j] - a[i] + 1;
                        int Y = d[j] - b[i] + 1;
                        if(X < 0 || Y < 0){
                                continue;
                        }
                        shit[X] = max(shit[X], Y);
                }
        }
        int res = 1e9;
        for(int i = Q - 2; i >= 0; i--){
                shit[i] = max(shit[i], shit[i + 1]);
                res = min(res, i + shit[i + 1]);
        }
        cout << res << "\n";
}