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
        set<int> s;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            s.insert(x);
        }
        cout << ((int)s.size() == 1 ? n : 1) << "\n";
    }
    return 0;
}