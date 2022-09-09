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
        string s;
        cin >> n >> s;
        auto ans = make_pair(s, 1);
        for(int i = 2; i <= n; i += 1){
            string t = s.substr(0, i - 1);
            if((n - i) % 2 == 0) reverse(t.begin(), t.end());
            t = s.substr(i - 1) + t;
            ans = min(ans, make_pair(t, i));
        }
        cout << ans.first << "\n" << ans.second << "\n";
    }
    return 0;
}