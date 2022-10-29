#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;
typedef pair<string, string> PS;
const DB eps = 1e-6;
const int N = 1e3 +7;
const int MOD = 1e9 + 7;
const LL INF = 3e18 + 7;

int a[105], b[105];

bool check(LL x){
    if ((LL)sqrt(x) * (LL)sqrt(x) == x) return 1; return 0;
}
void gen(int a[], int n){
    for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++)
    if (check(i * i * (n - 1) + j * j)){
        a[1] = j;
        for (int k = 2; k <= n; k++) a[k] = i;
        return;
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    gen(a, n);
    gen(b, m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < m; j++)
            printf("%d ", a[i] * b[j]);
        printf("%d\n", a[i] * b[m]);
    }

}