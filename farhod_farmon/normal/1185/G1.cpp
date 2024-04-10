#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 15;
const int mod = 1e9 + 7;

using namespace std;

int n;
int T;
int a[N];
int b[N];
int d[1 << N][N];

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> T;
        for(int i = 0; i < n; i++){
                cin >> a[i] >> b[i];
                d[1 << i][i] = 1;
        }
        for(int i = 1; i < (1 << n); i++){
                for(int j = 0; j < n; j++){
                        if(d[i][j] == 0){
                                continue;
                        }
                        for(int h = 0; h < n; h++){
                                if(i & (1 << h) || b[j] == b[h]){
                                        continue;
                                }
                                int ni = i | (1 << h);
                                add(d[ni][h], d[i][j]);
                        }
                }
        }
        int res = 0;
        for(int i = 0; i < (1 << n); i++){
                int S = 0;
                for(int j = 0; j < n; j++){
                        if(i & (1 << j)){
                                S += a[j];
                        }
                }
                if(S == T){
                        for(int j = 0; j < n; j++){
                                add(res, d[i][j]);
                        }
                }
        }
        cout << res << "\n";
}