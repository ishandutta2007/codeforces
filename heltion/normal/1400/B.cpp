#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL p, f, cnt_s, cnt_w, s, w, ans = 0;
        cin >> p >> f >> cnt_s >> cnt_w >> s >> w;
        for(int i = 0; i <= cnt_s; i += 1)
            if(s * i <= p){
                LL j = min(cnt_w, (p - s * i) / w);
                LL rs = cnt_s - i, rw = cnt_w - j, pans = i + j;
                if(s >= w){
                    LL fj = min(rw, f / w);
                    LL fi = min(rs, (f - w * fj) / s);
                    pans += fi + fj;
                }
                else{
                    LL fi = min(rs, f / s);
                    LL fj = min(rw, (f - s * fi) / w);
                    pans += fi + fj;
                }
                ans = max(ans, pans);
            }
        cout << ans << "\n";
    }
    return 0;
}