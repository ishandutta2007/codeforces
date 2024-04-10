#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int& _ : x) cin >> _;
        set<int> s;
        for(int i = 0; i < n; i += 1)
            for(int j = i + 1; j < n; j += 1)
                s.insert(x[j] - x[i]);
        cout << s.size() << "\n";
    }
    return 0;
}