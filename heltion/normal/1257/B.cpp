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
        int x, y;
        cin >> x >> y;
        cout << ( x >= 4 or (x >= 2 and y <= 3) or (x == 1 and y == 1) ? "YES\n" : "NO\n");
    }
    return 0;
}