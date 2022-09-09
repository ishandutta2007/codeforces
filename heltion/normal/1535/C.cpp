#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        int type = 0, cnt = 0;
        LL ans = 0;
        for(int i = 0, j = 0; i < (int)s.size(); i += 1){
            while(j < (int)s.size()){
                if(s[j] == '?') j += 1;
                else if(cnt == 0 or type == (s[j] - '0') ^ (j % 2)){
                    cnt += 1;
                    type = (s[j] - '0') ^ (j % 2);
                    j += 1;
                }
                else break;
            }
            ans += j - i;
            if(s[i] != '?') cnt -= 1;
        }
        cout << ans << "\n";
    }
    return 0;
}