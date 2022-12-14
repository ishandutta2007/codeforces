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

const int maxn = 200000;
int a[maxn], l[maxn], r[maxn];

int main(){
    int n;
    scanf("%d", &n);
    if (n == 1){
        puts("1");
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        l[i] = 1;
        r[i] = 1;
    }
    int now = 1;
    for (int i = 2; i <= n; ++i)
        if (a[i] <= a[i - 1]) now = i; else l[i] = i - now + 1;
    now = n;
    for (int j = n - 1; j >= 1; --j)
        if (a[j] >= a[j + 1]) now = j; else r[j] = now- j + 1;
    int ans = max(r[2] + 1, l[n - 1] + 1);
    for (int i = 2; i <= n - 1; ++i){
        if (a[i - 1] + 1 < a[i + 1]){
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
        } else ans = max(max(ans, l[i - 1] + 1), r[i + 1] + 1);
    }
    printf("%d\n", ans);
    return 0;
}