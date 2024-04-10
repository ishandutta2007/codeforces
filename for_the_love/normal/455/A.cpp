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

typedef long double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

LL f[N], cnt[N];


int main(){
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        cnt[x]++;
    }
    f[1] = cnt[1];
    for (int i = 2; i <= 100000; i++) f[i] = max(f[i - 1], f[i - 2] + cnt[i] * i);
    printf("%I64d\n", f[100000]);
}