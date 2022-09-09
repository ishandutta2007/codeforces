#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //6,10,14
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        if(n <= 30) cout << "NO\n";
        else if(n == 36) cout << "YES\n5 6 10 15\n";
        else if(n == 40) cout << "YES\n6 9 10 15\n";
        else if(n == 44) cout << "YES\n6 7 10 21\n";
        else cout << "YES\n6 10 14 " << n - 30 << "\n";
    }
    return 0;
}