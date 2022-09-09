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
        cin >> n;
        int cnt[2] = {};
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            cnt[a] += 1;
        }
        if(cnt[0] >= n / 2){
            cout << n / 2 << "\n";
            for(int i = 0; i < n / 2; i += 1) cout << "0 ";
        }
        else{
            int m = n / 2;
            if(m & 1) m += 1;
            cout << m << "\n";
            for(int i = 0; i < m; i += 1) cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}