#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, ans = 1, sum = 0, k = -1;
        string s;
        cin >> n >> s;
        for(char c : s){
            ans += k == c;
            k = c;
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}