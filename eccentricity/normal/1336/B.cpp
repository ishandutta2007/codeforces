#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        set<LL> sr, sg, sb;
        auto input = [](set<LL>& s, int n){
            for(int i = 0, _; i < n; i += 1){
                cin >> _;
                s.insert(_);
            }
        };
        input(sr, nr);
        input(sg, ng);
        input(sb, nb);
        LL ans = LLONG_MAX;
        auto loss = [](LL x, LL y, LL z)->LL{
            return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
        };
        auto cmp = [&](set<LL>& A, set<LL>& B, set<LL>& C){
            for(LL b : B){
                auto ita = A.upper_bound(b);
                if(ita == A.begin()) continue;
                auto itc = C.lower_bound(b);
                if(itc == C.end()) continue;
                ans = min(ans, loss(b, *prev(ita), *itc));
            }
        };
        cmp(sr, sg, sb);
        cmp(sr, sb, sg);
        cmp(sg, sr, sb);
        cmp(sg, sb, sr);
        cmp(sb, sr, sg);
        cmp(sb, sg, sr);
        cout << ans << "\n";
    }
    return 0;
}