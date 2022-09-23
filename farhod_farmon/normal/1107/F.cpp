#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long a[N];
long long b[N];
long long c[N];
long long d[N][N];
vector < int > v;

bool cmp(int x, int y)
{
        return b[x] > b[y];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i] >> c[i];
                v.push_back(i);
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        d[i][j] = -1e18;
                }
        }
        d[0][0] = 0;
        for(int ii = 1; ii <= n; ii++){
                int i = v[ii - 1];
                for(int j = n; j >= 0; j--){
                        for(int h = n - j; h >= 0; h--){
                                if(j - 1 >= 0){
                                        d[j][h] = max(d[j][h], d[j - 1][h] - min((long long)j - 1, c[i]) * b[i] + a[i]);
                                }
                                if(h - 1 >= 0){
                                        d[j][h] = max(d[j][h], d[j][h - 1] - c[i] * b[i] + a[i]);
                                }
                        }
                }
        }
        long long res = 0;
        for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                        res = max(res, d[i][j]);
                }
        }
        cout << res << "\n";
}