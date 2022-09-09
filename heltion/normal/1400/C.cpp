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
        int x;
        cin >> s >> x;
        int n = s.size();
        string t(n, '1'), r(n, '0');
        for(int i = 0; i < n; i += 1)
            if(s[i] == '0'){
                if(i >= x) t[i - x] = '0';
                if(i + x < n) t[i + x] = '0';
            }
        for(int i = 0; i < n; i += 1){
            if(i >= x and t[i - x] == '1') r[i] = '1';
            if(i + x < n and t[i + x] == '1') r[i] = '1';
        }
        if(s == r) cout << t << "\n";
        else cout << "-1\n";
    }
    return 0;
}