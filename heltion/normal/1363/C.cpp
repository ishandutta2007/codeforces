#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, d = 0;
        cin >> n >> x;
        for(int i = 1, u, v; i < n; i += 1){
            cin >> u >> v;
            d += u == x;
            d += v == x;
        }
        if(d <= 1 or n % 2 == 0) cout << "Ayush\n";
        else cout << "Ashish\n";
    }
    return 0;
}