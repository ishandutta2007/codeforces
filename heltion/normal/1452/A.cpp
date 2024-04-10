#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        cout << x + y + max(0, y - x - 1) << "\n";
    }
    return 0;
}