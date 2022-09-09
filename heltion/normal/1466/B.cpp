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
        for(int i = n - 1; i >= 0; i -= 1)
            if(i == n - 1 or x[i] + 1 < x[i + 1]) x[i] += 1;
        set<int> s;
        for(int _ : x) s.insert(_);
        cout << s.size() << "\n";
    }
    return 0;
}