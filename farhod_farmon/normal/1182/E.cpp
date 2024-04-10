#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

long long pw(long long x, long long n)
{
        n %= mod - 1;
        if(n < 0){
                n += mod - 1;
        }
        x %= mod;
        long long res = 1;
        while(n > 0){
                if(n & 1){
                        res = res * x % mod;
                }
                x = x * x % mod;
                n /= 2;
        }
        return res;
}

vector < vector < long long > > mul(vector < vector < long long > > x, vector < vector < long long > > y)
{
        vector < vector < long long > > res(x.size());
        for(int i = 0; i < res.size(); i++){
                while(res[i].size() < y[0].size()){
                        res[i].push_back(0);
                }
        }
        for(int i = 0; i < res.size(); i++){
                for(int j = 0; j < res[i].size(); j++){
                        for(int h = 0; h < x[0].size(); h++){
                                res[i][j] = (res[i][j] + x[i][h] * y[h][j]) % (mod - 1);
                        }
                }
        }
        return res;
}

vector < vector < long long > > pw(vector < vector < long long > > x, long long n)
{
        if(n == 1){
                return x;
        } else if(n & 1){
                return mul(x, pw(x, n - 1));
        } else{
                return pw(mul(x, x), n / 2);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long n, f1, f2, f3, c;
        cin >> n >> f1 >> f2 >> f3 >> c;
        vector < vector < long long > > M(5);
        for(int i = 0; i < 5; i++){
                while(M[i].size() < 5){
                        M[i].push_back(0);
                }
        }
        M[0][0] = M[1][0] = M[2][0] = M[0][1] = M[1][2] = M[3][3] = M[4][3] = M[4][4] = 1;
        M[3][0] = 2;
        M[4][0] = -6;
        vector < vector < long long > > v(1);
        v[0] = {0, 0, 0, 4, 1};
        v = mul(v, pw(M, n - 3));
        long long res = pw(c, v[0][0]);
        for(int i = 0; i < 5; i++){ for(int j = 0; j < 5; j++){ M[i][j] = 0;}}
        M[0][0] = M[1][0] = M[2][0] = M[0][1] = M[1][2] = 1;
        v = mul({{1, 0, 0, 0, 0}}, pw(M, n - 3));
        res = res * pw(f3, v[0][0]) % mod;
        v = mul({{0, 1, 0, 0, 0}}, pw(M, n - 3));
        res = res * pw(f2, v[0][0]) % mod;
        v = mul({{0, 0, 1, 0, 0}}, pw(M, n - 3));
        res = res * pw(f1, v[0][0]) % mod;
        cout << res << "\n";
}