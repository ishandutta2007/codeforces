#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, t, a[305], v[305], to[305], b[305], used[305], f[100005], sum, i, j, x, y;
long long tmp;
vector <int> vec;
int main(){
    scanf("%d%d%d", &n, &m, &t);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        to[x] = y;
        b[y] = 1;
    }
    for (i = 1; i <= n; i++)
    if (!b[i]){
        memset(v, 0, sizeof(v));
        x = i;
        sum = 0;
        do{
            used[x] = 1;
            tmp += sum;
            sum += a[x];
            vec.push_back(sum);
            if (v[x]){
                printf("0\n");
                return 0;
            }
            v[x] = 1;
            x = to[x];
        }while (x);
    }
    for (i = 1; i <= n; i++)
    if (!used[i]){
        printf("0\n");
        return 0;
    }
    if (tmp > t){
        printf("0\n");
        return 0;
    }
    t -= tmp;
    f[0] = 1;
    for (i = 0; i < vec.size(); i++)
    for (j = 0; j <= t; j++)
    if (vec[i] <= j) f[j] = (f[j - vec[i]] + f[j]) % MOD;
    printf("%d\n", f[t]);
}