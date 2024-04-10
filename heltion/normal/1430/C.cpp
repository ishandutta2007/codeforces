#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        cout << "2\n";
        if(n > 2){
            cout << n - 2 << " " << n << "\n";
            cout << n - 1 << " " << n - 1 << "\n";
            for(int i = n - 1; i >= 3; i -= 1)
                cout << i << " " << i - 2 << "\n";
        }
        else cout << "1 2\n";
    }
    return 0;
}