#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << "\n";
    }
    return 0;
}