#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 200000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        int m = (n + 3) / 4;
        for(int i = 0; i < n - m; i += 1) cout << "9";
        for(int i = 0; i < m; i += 1) cout << "8";
        cout << "\n";
    }
    return 0;
}