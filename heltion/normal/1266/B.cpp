#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //14 + (15 - 20)
    int t;
    for(cin >> t; t; t -= 1){
        LL x;
        cin >> x;
        cout << (x > 14 and x % 14 >= 1 and x % 14 <= 6 ? "YES\n" : "NO\n");
    }
    return 0;
}