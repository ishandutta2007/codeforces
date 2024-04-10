#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 202;

using namespace std;

int A, B, C;
long long a[N], b[N], c[N];
long long d[N][N][N];

void upd(long long &x, long long y)
{
        x = max(x, y);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> A >> B >> C;
        for(int i = 1; i <= A; i++) cin >> a[i];
        for(int i = 1; i <= B; i++) cin >> b[i];
        for(int i = 1; i <= C; i++) cin >> c[i];
        sort(a + 1, a + A + 1);
        sort(b + 1, b + B + 1);
        sort(c + 1, c + C + 1);
        for(int i = 0; i <= A; i++){
                for(int j = 0; j <= B; j++){
                        for(int h = 0; h <= C; h++){
                                if(i > 0) upd(d[i][j][h], d[i - 1][j][h]);
                                if(j > 0) upd(d[i][j][h], d[i][j - 1][h]);
                                if(h > 0) upd(d[i][j][h], d[i][j][h - 1]);
                                if(i > 0 && j > 0) upd(d[i][j][h], d[i - 1][j - 1][h] + a[i] * b[j]);
                                if(i > 0 && h > 0) upd(d[i][j][h], d[i - 1][j][h - 1] + a[i] * c[h]);
                                if(j > 0 && h > 0) upd(d[i][j][h], d[i][j - 1][h - 1] + b[j] * c[h]);
                        }
                }
        }
        cout << d[A][B][C] << "\n";
}