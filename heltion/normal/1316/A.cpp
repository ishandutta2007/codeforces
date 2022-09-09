#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m, sum = 0;
        cin >> n >> m;
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            sum += a;
        }
        cout << min(sum, m) << "\n";
    }
    return 0;
}