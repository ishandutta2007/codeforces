#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 21;
const int M = 1 << 21;
int a[M], b[M], B[M], n, m;
LL r[N], R[N], T[N];


inline int lowbit(int x){return x & -x;}

void Add(int x, int d){
    for (; x <= m; x += lowbit(x)) B[x] += d;
}
int Query(int x){
    if (x > m) x = m;
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += B[x];
    return ret;
}

map <int, int> S;
int main(){

    scanf("%d", &n);
    for (int i = 1; i <= 1 << n; i++){
        scanf("%d", &a[i]);
        b[i - 1] = a[i];
    }
    sort(b, b + (1 << n));
    m = unique(b, b + (1 << n)) - b;
    for (int i = 0; i < m; i++) S[b[i]] = i + 1;
    for (int i = 1; i <= 1 << n; i++) a[i] = S[a[i]];

    for (int i = 1; i <= 1 << n; i++)
    for (int j = 0; j <= n; j++)
    if (i % (1 << j) == 0){
        for (int k = 0; k < 1 << j; k++){
            Add(a[i - k], 1);
            r[j] += Query(a[i - k] - 1);
        }
        for (int k = 0; k < 1 << j; k++){
            T[j] += Query(a[i - k] - 1);
            T[j] += Query(m) - Query(a[i - k]);
            //cout << Query(m) << " " << Query(a[i - k] + 1) << " " << Query(a[i - k] - 1) << endl;
        }

        for (int k = 0; k < 1 << j; k++)
            Add(a[i - k], -1);
    }
    for (int i = 0; i <= n; i++) T[i] /= 2;
    int cas, x;
    scanf("%d", &cas);
    while (cas--){
        scanf("%d", &x);
        for (int i = 0; i <= x; i++) R[i] = T[i] - r[i];

        for (int i = x + 1; i <= n; i++){
            LL t = 1 << i;
            R[i] = r[i] - r[i - 1] + R[i - 1];
        }
        memcpy(r, R, sizeof(R));
        printf("%I64d\n", r[n]);
    }
}