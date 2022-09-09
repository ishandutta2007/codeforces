#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cout << 4 + 3 * n << "\n";
    cout << "0 0\n";
    cout << "0 1\n";
    cout << "1 0\n";
    cout << "1 1\n";
    for(int i = 0; i < n; i += 1){
        cout << (i + 2) << " " << (i + 2) << "\n";
        cout << (i + 2) << " " << (i + 1) << "\n";
        cout << (i + 1) << " " << (i + 2) << "\n";
    }
    return 0;
}
//XX 
//XXX
// XXX
//  XX