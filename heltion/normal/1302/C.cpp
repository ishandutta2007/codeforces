#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if((y - x) % (b + a) == 0) cout << (y - x) / (b + a) << "\n";
        else cout << "-1\n";
    }
    return 0;
}