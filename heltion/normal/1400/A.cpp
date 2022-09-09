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
        string s, t;
        cin >> n >> s;
        for(int i = 0; i < n; i += 1)
            t.push_back(s[i * 2]);
        cout << t << "\n";
    }
    return 0;
}