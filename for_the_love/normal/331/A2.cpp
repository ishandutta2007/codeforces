#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e7 + 7;


long long v[300005], a[300005], s[300005], next[300005], S[300005], n, t, cnt, index[MOD];

int Get(long long x){
    long long p = index[(x + MOD * 1000) % MOD];
    while (p != -1){
        if (a[p] == x) return p;
        p = next[p];
    }
    return -1;
}
int main(){
    cin >> n;
    memset(next, -1, sizeof(next));
    memset(index, -1, sizeof(index));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        long long t = Get(a[i]);
        if (t == -1){
            S[i] = ++cnt;
            next[i] = index[(a[i] + MOD * 1000) % MOD];
            index[(a[i] + MOD * 1000) % MOD] = i;
        }else S[i] = S[t];
        if (a[i] < 0) s[i] = s[i - 1]; else s[i] = s[i - 1] + a[i];
    }

    long long ans = -1e16;
    long long l, r;
    for (int i = 1; i <= n; i++){
        t = S[i];
        if (v[t]){
            if (ans < s[i - 1] - s[v[t]] + a[i] * 2){
                ans = s[i - 1] - s[v[t]] + a[i] * 2;
                l = v[t];
                r = i;
            }
        } else v[t] = i;
    }
    int ansk = l - 1 + n - r;
    for (int i = l + 1; i < r; i++)
    if (a[i] < 0) ansk++;

    cout << ans << " " << ansk << endl;
    for (int i = 1; i < l; i++) cout << i << " ";
    for (int i = l + 1; i < r; i++)
    if (a[i] < 0) cout << i << " ";
    for (int i = r + 1; i <= n; i++) cout << i << " ";

}