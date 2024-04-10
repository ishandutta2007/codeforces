#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            mp[a] += 1;
        }
        vector<int> v;
        for(auto [x, y] : mp) v.push_back(y);
        int m = *max_element(v.begin(), v.end()), c = count(v.begin(), v.end(), m);
        cout << (n - c) / (m - 1) - 1 << "\n";
    }
    return 0;
}