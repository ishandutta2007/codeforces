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
        vector<int> v(n);
        for(int &x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>());
        LL A = 0, B = 0;
        for(int i = 0; i < n; i += 1){
            if(i % 2 == 0){
                if(v[i] % 2 == 0) A += v[i];
            }
            else if(v[i] & 1) B += v[i];
        }
        if(A > B) cout << "Alice\n";
        else if(A < B) cout << "Bob\n";
        else cout << "Tie\n";
    }
    return 0;
}