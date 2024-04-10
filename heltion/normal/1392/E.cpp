#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 25 + 1;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        for(int j = 1; j <= n; j += 1){
            if(i & 1) cout << "0 ";
            else cout << (1LL << (i + j - 2)) << " ";
        }
        cout << "\n";
    }
    cout << flush;
    int q;
    for(cin >> q; q; q -= 1){
        LL k;
        cin >> k;
        int x = 1, y = 1;
        cout << x << " " << y << "\n";
        for(int i = 1; i < 2 * n - 1; i += 1){
            if(((k >> i) & 1) ^ (x & 1)) y += 1;
            else x += 1;
            cout << x << " " << y << "\n";
        }
        cout << flush;
    }
    return 0;
}