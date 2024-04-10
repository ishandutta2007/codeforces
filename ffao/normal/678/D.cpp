#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int A, B, x;
long long n;

#define SS 2
const int mod = 1000000007;

void copia(int A[SS][SS], int B[SS][SS]) {
    for (int i = 0; i < SS; i++) {
        for (int j = 0; j < SS; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void mult(int A[SS][SS], int B[SS][SS], int C[SS][SS]) {
    for (int i = 0; i < SS; i++) {
        for (int j = 0; j < SS; j++) {
            A[i][j] = 0;
            for (int k = 0; k < SS; k++) {
                A[i][j] = (A[i][j] + B[i][k] * 1ll * C[k][j]) % mod;
            }
        }
    }
}

int m[SS][SS];
int temp[SS][SS];
int res[SS][SS];

int main() {
    scanf("%d %d %lld %d", &A, &B, &n, &x);

    m[0][0] = A;
    m[0][1] = B;
    m[1][1] = 1;

    res[0][0] = res[1][1] = 1;

    while (n) {
        if (n & 1) {
            mult(temp, res, m);
            copia(res,temp);
        }
        mult(temp, m, m);
        copia(m, temp);
        n >>= 1;
    }

    //printf("%d %d\n", res[0][0],res[0][1]);
    int k = (res[0][0] * 1ll * x + res[0][1]) % mod;
    printf("%d\n", k);
}