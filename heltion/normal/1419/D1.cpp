#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    sort(v.begin(), v.end());
    vector<int> w(n);
    for(int i = 0; i < n; i += 1){
        if(2 * i + 1 < n) w[2 * i + 1] = v[i];
        else w[2 * (n - i - 1)] = v[i];
    }
    cout << (n - 1) / 2 << "\n";
    for(int x : w) cout << x << " ";
    return 0;
}