#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int f(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0; i < m; i += 1){
        int r, c;
        cin >> r >> c;
        mp[c] += r;
    }
    mp[n + 1] = 3;
    int x = 0, y = 3;
    for(auto [a, b] : mp){
        //cout << x << " " << y << "/" << a << " " << b << "\n";
        if(b == 3){
            if(y != 3) return 0;
            x = a;
        }
        if(b == 1){
            if(y == 3){
                x = a + 1;
                y = 2;
                continue;
            }
            if(y == 1){
                if((x - a) % 2 == 0) return 0;
            }
            if(y == 2){
                if((x - a) % 2 != 0) return 0;
            }
            x = a;
            y = 3;
        }
        if(b == 2){
            if(y == 3){
                x = a + 1;
                y = 1;
                continue;
            }
            if(y == 2){
                if((x - a) % 2 == 0) return 0;
            }
            if(y == 1){
                if((x - a) % 2 != 0) return 0;
            }
            x = a;
            y = 3;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1)
        cout << (f() ? "YES\n" : "NO\n");
    return 0;
}