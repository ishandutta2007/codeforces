#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


LL f[20][2];
int A[20];

LL Calc(int A[], int n, int first){
    memset(f, 0, sizeof(f));
    if (first < A[n]) f[1][0] = 1; else f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    for (int j = 0; j < 10; j++){
        int x = j; if (n == i){j = 10, x = first;}
        if (x < A[n - i + 1]){
            f[i][0] += f[i - 1][1] + f[i - 1][0];
        }else if (x > A[n - i + 1]){
            f[i][0] += f[i - 1][0];
        }else{
            f[i][0] += f[i - 1][0];
            f[i][1] += f[i - 1][1];
        }
    }
    return f[n][0] + f[n][1];
}

LL Solve(LL R){
    int n = 0;
    while (R){
        A[++n] = R % 10;
        R /= 10;
    }
    LL ret = 0, p = 1;

    for (int i = 1; i < n; i++){
        if (i == 1) ret += 9;
        else{
            ret += p * 9;
            p *= 10;
        }
    }
    for (int i = 1; i <= A[n]; i++) ret += Calc(A, n, i);
    return ret;
}


int main(){
    LL L, R;
    cin >> L >> R;
    cout << Solve(R) - Solve(L - 1) << endl;
}