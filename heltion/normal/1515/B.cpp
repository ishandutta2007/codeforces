#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    set<int> s;
    for(int i = 1; i * i * 2 <= 1000000000; i += 1) s.insert(i * i * 2);
    for(int i = 1; i * i * 4 <= 1000000000; i += 1) s.insert(i * i * 4);
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        cout << (s.count(n) ? "YES\n" : "NO\n");
    }
    return 0;
}