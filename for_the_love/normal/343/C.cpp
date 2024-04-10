#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111111;
long long a[N], b[N], n, m;

long long t(long long a, long long b){
    if (a > b) return a - b; else return b - a;
}

long long calc(int i, int j, int k){
    //if (a[i] >= b[k]) return a[i] - b[j];
    //if (a[i] <= b[j]) return b[k] - a[i];
    return min(t(a[i], b[j]), t(a[i], b[k])) + b[k] - b[j];
}


bool check(long long l){
    int j = 1, k = 1;
    for (int i = 1; i <= n; i++){
        while (calc(i, j, k) <= l && k <= m) k++;
        j = k;
        if (k > m) return 1;
    }
    return 0;
}

int main(){
    //scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    long long l = 0, r = 1e11, ans;
    while (l <= r){
        long long mid = (l + r) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}