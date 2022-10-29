#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, k, i, L, R, t, l[100005], r[100005], d[100005], a[100005], s[100005], S[100005];
int main(){
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= m; i++) cin >> l[i] >> r[i] >> d[i];
    for (i = 1; i <= k; i++){
        cin >> L >> R;
        s[L]++; s[R + 1]--;
    }
    t = 0;
    for (i = 1; i <= m; i++){
        t += s[i];
        S[l[i]] += d[i] * t;
        S[r[i] + 1] -= d[i] * t;
    }
    t = 0;
    for (i = 1; i <= n; i++){
        t += S[i];
        cout << t + a[i] << " ";
    }
}