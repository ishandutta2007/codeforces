#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        int cnt[3] = {};
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            cnt[x] += 1;
        }
        if(cnt[1] & 1) cout << "NO\n";
        else if(cnt[1] == 0 and (cnt[2] & 1)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}