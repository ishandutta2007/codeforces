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

const int maxn = 111111;
LL f[maxn];
int a[maxn];
int n;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    f[0] = 0;
    f[1] = a[1];
    for (int i = 2; i <= 100000; ++i){
        f[i] = max(f[i - 1], f[i - 2] + (LL)a[i] * (LL)i);
    }
    cout << f[100000] << endl;
    return 0;
}