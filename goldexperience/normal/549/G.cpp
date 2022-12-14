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

int a[222222];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        a[i] += i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i] -= i;
    bool flag = true;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1]) flag = false;
    if (flag){
        for (int i = 0; i < n - 1; ++i)
            printf("%d ", a[i]);
        printf("%d\n", a[n - 1]);
    } else puts(":(");
    return 0;
}