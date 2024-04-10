#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        set<int> s;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            s.insert(x);
        }
        if(s.size() < n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}