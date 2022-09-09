#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    for(cin >> t; t; t -= 1){
        cin >> n;
        for(int i = 0, k = 1, a; i < n; i += 1, k = -k){
            cin >> a;
            cout << abs(a) * k << " ";
        }
        cout << "\n";
    }
    return 0;
}