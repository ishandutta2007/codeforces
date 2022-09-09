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
        multiset<int> s;
        for(int i = 0, x; i < n; i += 1){
            cin >> x;
            s.insert(x);
        }
        int d = *prev(s.end());
        s.erase(s.find(d));
        cout << d << " ";
        while(not s.empty()){
            int x = *s.begin();
            for(int y : s) if(gcd(d, y) >= gcd(d, x)) x = y;
            s.erase(s.find(x));
            cout << x << " ";
            d = gcd(d, x);
        }
        cout << "\n";
    }
    return 0;
}