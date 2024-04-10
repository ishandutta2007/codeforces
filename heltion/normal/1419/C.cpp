#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -=1){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        int ok = 1;
        for(int x : v) if(x != m) ok = 0;
        if(ok){
            cout << "0\n";
            continue;
        }
        for(int x : v) if(x == m) ok = 1;
        if(ok){
            cout << "1\n";
            continue;
        }
        int sum = 0;
        for(int x : v) sum += x;
        if(sum == n * m){
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
    return 0;
}