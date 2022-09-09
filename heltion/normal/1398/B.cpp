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
        s.push_back('0');
        int p = 0;
        vector<int> v;
        for(auto c : s) if(c == '0'){
            if(p) v.push_back(p);
            p = 0;
        }
        else p += 1;
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i < (int)v.size(); i += 2) ans += v[i];
        cout << ans << "\n";
    }
    return 0;
}