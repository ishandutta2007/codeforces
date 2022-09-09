#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, y;
        cin >> n >> x >> y;
        cout << min(n, max(1, x + y + 1 - n)) << " " << min(n, x + y - 1) << "\n";
    }
    return 0;
}