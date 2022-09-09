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
        LL sum = 0, m = 0, x;
        for(int i = 0; i < n; i += 1){
            cin >> x;
            sum += x;
            m = max(m, x);
        }
        cout << max(m * (n - 1), (sum + n - 2) / (n - 1) * (n - 1)) - sum << "\n";
    }
    return 0;
}