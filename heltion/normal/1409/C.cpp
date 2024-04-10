#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, y;
        cin >> n >> x >> y;
        for(int i = 1; i <= y - x; i += 1) if((y - x) % i == 0)
            if((y - x) / i + 1 <= n){
                int k = y - (n - 1) * i;
                while(k <= 0) k += i;
                for(int j = 1; j <= n; j += 1) cout << k + (j - 1) * i << " ";
                cout << "\n";
                break;
            }
    }
    return 0;
}