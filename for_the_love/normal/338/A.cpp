#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 9;
struct Matrix{
    long long mat[3][3];
} e;

Matrix Mul(Matrix a, Matrix b){
    Matrix ret;
    for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++){
        ret.mat[i][j] = 0;
        for (int k = 1; k <= 2; k++){
            ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            ret.mat[i][j] %= MOD;
        }
    }
    return ret;
}
Matrix Power(Matrix e, long long b){
    if (b == 1) return e;
    Matrix t = Power(e, b / 2);
    t = Mul(t, t);
    if (b & 1) t = Mul(t, e);
    return t;
}


int main(){
    long long n, m, k, must, space;
    cin >> n >> m >> k;
    if (m % (k - 1) == 0) space = m / (k - 1) - 1; else space = m / (k - 1);
    //space = min(n - m, space);
    if (n - m >= space) cout << m % MOD << endl;
    else{
        must = (m - (n - m) * (k - 1)) / k;
        e.mat[1][1] = 2;
        e.mat[1][2] = 2;
        e.mat[2][1] = 0;
        e.mat[2][2] = 1;
        Matrix t;
        if (!must){
            t.mat[1][1] = 1;
            t.mat[1][2] = 0;
            t.mat[2][1] = 0;
            t.mat[2][2] = 1;
        }else t = Power(e, must);
        cout << (t.mat[1][2] * k + (m - must * k)) % MOD << endl;
    }


}