#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        int ans = 0, a = 0, b = 0;
        for(char c : s){
            if(c == '(') a += 1;
            if(c == '[') b += 1;
            if(c == ')' and a){
                a -= 1;
                ans += 1;
            }
            if(c == ']' and b){
                b -= 1;
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}