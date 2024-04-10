#include <map>
#include <set>
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

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int x[1111], y[1111], v[1111];

int main(){
    int n, X, Y;
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    if (!v[i]){
        v[i] = 1;
        ans ++;
        for (int j = 0; j < n; j++)
        if (!v[j]){
            if ((x[i] - X) * (y[j] - Y) - (x[j] - X) * (y[i] - Y) == 0) v[j] = 1;
        }
    }
    printf("%d\n", ans);

}