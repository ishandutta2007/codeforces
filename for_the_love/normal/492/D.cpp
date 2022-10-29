#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
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
const int N = int(2e6) + 9;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

int check(LL a, LL A, LL b, LL B){
    a *= B, b *= A;
    if (a == b) return 0;
    if (a > b) return 1;
    return 2;
}

int A, B, ans[N];
void gao(int x){
    int t = x - (x - 1) / (A + B) * (A + B);
    if (ans[t] == 3) puts("Both");
    else if (ans[t] == 1) puts("Vanya");
    else puts("Vova");
}

int main() {
    int n;
    scanf("%d%d%d", &n, &A, &B);

    int a = 1, b = 1;
    for (int i = 1; i <= A + B; i++){
        int op = check(a, A, b, B);
        if (op == 0){
            ans[i] = ans[i + 1] = 3;
            a++, b++, i++;
        }else if (op == 1){
            ans[i] = 2;
            b++;
        }else{
            ans[i] = 1;
            a++;
        }
    }

    int g = gcd(A, B), x;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        gao(x);
    }

}