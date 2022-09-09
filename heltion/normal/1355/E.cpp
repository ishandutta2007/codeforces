#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
LL h[maxn + 1], s[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL N, A, R, M;
    cin >> N >> A >> R >> M;
    M = min(A + R, M);
    for(int i = 1; i <= N; i += 1) cin >> h[i];
    sort(h + 1, h + N + 1);
    for(int i = 1; i <= N; i += 1) s[i] = s[i - 1] + h[i];
    LL l = 0, r = 1000000000;
    while(l < r){
        LL m = (l + r) >> 1;
        LL SG = 0, SL = 0;
        for(int i = 1; i <= N; i += 1)
            if(h[i] >= m) SG += h[i] - m;
            else SL += m - h[i];
        if(SL >= SG) r = m;
        else l = m + 1;
    }
    LL ans = LLONG_MAX;
    for(int i = 1; i < N; i += 1){
        LL sL = h[i], sR = h[i + 1];
        if(sL < r){
            int rL = sL, rR = min(sR, r - 1);
            //(x * i - s[i]) * (M - R) + (s[N] - s[i] - x * (N - i)) * R
            LL k = i * (M - R) - (N - i) * R , b = -s[i] * (M - R) + (s[N] - s[i]) * R;
            ans = min(ans, k * rL + b);
            ans = min(ans, k * rR + b);
        }
        if(sR >= r){
            int rL = max(sL, r), rR = sR;
            //(s[N] - s[i] - x * (N - i)) * (M - A) + (x * i - s[i]) * A
            LL k = - (N - i) * (M - A) + i * A , b = (s[N] - s[i]) * (M - A) + - s[i] * A;
            ans = min(ans, k * rL + b);
            ans = min(ans, k * rR + b);
        }
    }
    //SG = h>=H (h - H)
    //SL = h<=H (H - h)
    //SG >= SL SL * (M - R) + SG * R
    //SL >= SG SG * (M - A) + SL * A
    cout << ans;
    return 0;
}