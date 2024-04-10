#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;



int a[N];

int main(){
    int n;
    long long A, sum = 0;
    scanf("%d%I64d", &n, &A);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for (int i = 1; i <= n; i++){
        int u, d;
        if (A - n + 1 < a[i]){
            u = A - n + 1;
        }else u = a[i];
        if (A - sum + a[i] > 0){
            d = A - sum + a[i];
        }else d = 1;
        if (d > u) printf("%d ", a[i]);
        else printf("%d ", a[i] - (u - d + 1));
    }
    puts("");

}