#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s, t;
        cin >> s >> t;
        int k = s.size() * t.size() / gcd(s.size(), t.size());
        string rs, rt;
        for(int i = 0; i < k; i += s.size()) rs += s;
        for(int i = 0; i < k; i += t.size()) rt += t;
        if(rs == rt) cout << rs << "\n";
        else cout << "-1\n";
    }
    return 0;
}