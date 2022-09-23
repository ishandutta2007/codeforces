#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

long long d[33][3][3][3];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long l, r;
                cin >> l >> r;
                vector < int > a, b;
                for(int i = 30; i >= 0; i--){
                        a.push_back((l >> i) & 1);
                        b.push_back((r >> i) & 1);

                        for(int j = 0; j < 2; j++){
                                d[i][j][0][0] = 0;
                                d[i][j][0][1] = 0;
                                d[i][j][1][0] = 0;
                                d[i][j][1][1] = 0;
                        }
                }

                long long res = 0;
                d[0][0][0][0] = 1;
                for(int i = 1; i <= 30; i++){
                        for(int k = 0; k < 2; k++){
                                for(int j = 0; j < 2; j++){
                                        for(int h = 0; h < 2; h++){
                                                for(int x = 0; x < 2; x++){
                                                        for(int y = 0; y < 2; y++){
                                                                if(y == 1 && x == 1){
                                                                        continue;
                                                                }
                                                                int nj = j, nh = h, nk = k;
                                                                if(j == 0){
                                                                        if(x < a[i]){
                                                                                continue;
                                                                        } else if(x > a[i]){
                                                                                nj = 1;
                                                                        }
                                                                }
                                                                if(h == 0){
                                                                        if(y > b[i]){
                                                                                continue;
                                                                        } else if(y < b[i]){
                                                                                nh = 1;
                                                                        }
                                                                }
                                                                if(k == 0){
                                                                        if(x > y){
                                                                                continue;
                                                                        } else if(x < y){
                                                                                nk = 1;
                                                                        }
                                                                }
                                                                d[i][nk][nj][nh] += d[i - 1][k][j][h];
                                                        }
                                                }
                                        }
                                }
                        }
                }
                res += d[30][1][0][0];
                res += d[30][1][0][1];
                res += d[30][1][1][0];
                res += d[30][1][1][1];
                res *= 2;
                if(l == 0){
                        res += 1;
                }

                cout << res << "\n";
        }
}