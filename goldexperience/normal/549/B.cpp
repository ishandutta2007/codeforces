#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 111;
int n;
bool c[maxn][maxn];
int a[maxn], b[maxn];
char buf[maxn];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%s", buf + 1);
        for (int j = 1; j <= n; ++j)
            if (buf[j] == '1') c[i][j] = true; else c[i][j] = false;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    vector<int> vec;
    for (int i = 1; i <= n; ++i) a[i] = 0;
    for (int i = 1; i <= n; ++i){
        int k = -1;
        for (int j = 1; j <= n; ++j)
            if (b[j] == a[j]){
                k = j;
                break;
            }
        if (k == -1) break;
        vec.push_back(k);
        for (int j = 1; j <= n; ++j)
            if (c[k][j]) ++a[j];
    }
    printf("%d\n", sz(vec));
    for (int i = 0; i < sz(vec); ++i)
        printf("%d\n", vec[i]);
    return 0;
}