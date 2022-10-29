//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int b[N], p[N], n, m, S;


int Calc(int l, int S){
    long long sum = 0;
    for (int i = 1; i <= l; i++){
        if (p[l - i + 1] <= b[n - i + 1]){
            sum += p[l - i + 1];
            continue;
        }
        S -= p[l - i + 1] - b[n - i + 1];
        sum += b[n - i + 1];
        if (S < 0) return -1;
    }
    return max(0ll, sum - S);
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
    sort(b + 1, b + n + 1);
    sort(p + 1, p + m + 1);
    int l = 0, r = min(n, m), A, B;
    while (l <= r){
        int mid = l + r >> 1;
        int t = Calc(mid, S);
        if (t != -1){
            A = mid;
            B = t;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << A << " " << B << endl;
}