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
        cout << (s.size() % 2 == 0 and s[0] != ')' and s.back() != '(' ? "YES\n" : "NO\n");
    }
    return 0;
}