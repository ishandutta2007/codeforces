#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, b, c;
        cin >> a >> b >> c;
        cout << a + b + c - 1 << "\n";
    }
    return 0;
}