#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b >= a) cout << b << "\n";
        else if(d >= c) cout << "-1\n";
        else cout << (a - b + c - d - 1) / (c - d) * c + b << "\n";
    }
    return 0;
}