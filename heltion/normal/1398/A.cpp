#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        if(v[0] + v[1] <= v[n - 1]) cout << "1 2 " << n << "\n";
        else cout << "-1\n";
    }
    return 0;
}