#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n;
        cin >> n;
        multiset<int> s;
        for(int i = 0, a; i < n; i += 1){
            cin >> a;
            s.insert(a);
        }
        for(int i = 0; s.count(i); i += 1){
            cout << i << " ";
            s.erase(s.find(i));
        }
        for(int x : s) cout << x << " ";
        cout << "\n";
    }
    return 0;
}