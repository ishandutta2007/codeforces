#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        cout << k / 2 + n - k << "\n";
        for(int i = (k + 1) / 2; i < k; i += 1) cout << i << " ";
        for(int i = k + 1; i <= n; i += 1) cout << i << " ";
        cout << "\n";
    }
    return 0;
}