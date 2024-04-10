#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 2;
LL A[maxn], D[maxn];
LL sum[maxn], pre[maxn], suf[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i += 1) cin >> A[i];
    for(int i = 1; i <= N; i += 1) cin >> D[i];
    for(int i = 1; i <= N; i += 1) sum[i] = sum[i - 1] + A[i];
    for(int i = 1; i <= N; i += 1) pre[i] = i == 1 ? D[i] : min(pre[i - 1], D[i]);
    for(int i = N; i >= 1; i -= 1) suf[i] = max(suf[i + 1], sum[N] - sum[i - 1] - D[i]);
    if(not K) cout << suf[1];
    else if(K == 1){
        LL ans = 0;
        for(int i = 2; i <= N; i += 1) ans = max(ans, suf[i] + max(0LL, sum[i - 1] - pre[i - 1]));
        for(int i = 2; i < N; i += 1) ans = max(ans, max(0LL, sum[N] - D[1] - A[i]) + max(0LL, A[i] - D[i]));
        cout << ans;
    }
    else cout << max(sum[N] - pre[N - 1], suf[N]);
    return 0;
}