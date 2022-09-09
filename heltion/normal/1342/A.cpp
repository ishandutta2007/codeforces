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
        LL x, y, a, b;
        cin >> x >> y >> a >> b;
        b = min(2 * a, b);
        cout << min(x, y) * b + (max(x, y) - min(x, y)) * a << "\n";
    }
    return 0;
}