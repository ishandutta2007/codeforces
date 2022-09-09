#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int a[maxn], sum[maxn], m[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    int L = 1, R = n;
    while(L < R){
        int M = (L + R + 1) / 2;
        int ok = 0;
        for(int i = 1; i <= n; i += 1){
            sum[i] = sum[i - 1];
            if(a[i] >= M) sum[i] += 1;
            else sum[i] -= 1;
            m[i] = min(m[i - 1], sum[i]);
        }
        for(int i = k; i <= n; i += 1)
            if(sum[i] > m[i - k]) ok = 1;
        if(ok) L = M;
        else R = M - 1;
    }
    cout << L;
    return 0;
}