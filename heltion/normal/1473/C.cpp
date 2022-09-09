#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= (2 * k - n - 1); i += 1) cout << i << " ";
        for(int i = 2 * k - n; i <= k; i += 1) cout << 3 * k - n - i << " ";
        cout << "\n";
    }
    return 0;
}