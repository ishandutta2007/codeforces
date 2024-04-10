#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        vector<int> s(4);
        for(int& x : s) cin >> x;
        int w0 = max(s[0], s[1]), w1 = max(s[2], s[3]);
        sort(s.begin(), s.end());
        cout << (min(w0, w1) == s[2] and max(w0, w1) == s[3] ? "YES\n" : "NO\n");
    }
    return 0;
}