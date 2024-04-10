#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        if(n == 1) cout << "0\n";
        else if(n == 2) cout << "1\n";
        else if(n == 3) cout << "2\n";
        else if(n % 2 == 0) cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}