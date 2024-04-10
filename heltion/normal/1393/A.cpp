#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, n;
    for(cin >> T; T; T -= 1){
        cin >> n;
        cout << n / 2 + 1 << "\n";
    }
    return 0;
}