#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    for(cin >> t; t; t -= 1){
        cin >> n;
        cout << (n + 1) / 2 << "\n";
    }
    return 0;
}