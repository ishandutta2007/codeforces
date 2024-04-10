#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int w, h, n;
        cin >> w >> h >> n;
        int x = w * h;
        cout << ((x & -x) >= n ? "YES\n" : "NO\n");
    }
    return 0;
}