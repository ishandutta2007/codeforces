#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        int ans = s.size();
        for(int i = 0; i < 10; i += 1) ans = min(ans, (int)s.size() - (int)count(s.begin(), s.end(), '0' + i));
        for(int i = 0; i < 10; i += 1)
            for(int j = 0; j < 10; j += 1)
                if(i != j){
                    int sum = 0;
                    for(char c : s) if((c == '0' + i and not(sum & 1)) or (c == '0' + j and (sum & 1))) sum += 1;
                    ans = min(ans, (int)s.size() - (sum & ~1));
                }
        cout << ans << "\n";
    }
    return 0;
}