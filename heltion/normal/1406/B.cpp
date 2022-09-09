#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<LL> p, ne;
        int zr = 0;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            if(x > 0) p.push_back(x);
            if(x < 0) ne.push_back(x);
            if(x == 0) zr += 1;
        }
        LL ans = zr ? 0 : LLONG_MIN;
        sort(p.begin(), p.end());
        sort(ne.begin(), ne.end());
        for(int i = 0; i <= 5; i += 1) if(p.size() >= i and ne.size() >= 5 - i){
            LL pans = 1;
            if(i & 1){
                for(int j = 0; j < i; j += 1) pans *= p[p.size() - j - 1];
                for(int j = 0; j < 5 - i; j += 1) pans *= ne[j];
                ans = max(ans, pans);
            }
            else{
                for(int j = 0; j < i; j += 1) pans *= p[j];
                for(int j = 0; j < 5 - i; j += 1) pans *= ne[ne.size() - j - 1];
                ans = max(ans, pans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}