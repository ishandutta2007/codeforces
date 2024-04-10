#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, m;
        cin >> n >> m;
        if(n == 1) cout << "0\n";
        else if(n == 2) cout << m << "\n";
        else cout << 2 * m << "\n";
    }
    return 0;
}