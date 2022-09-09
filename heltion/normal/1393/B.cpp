#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    int r2 = 0, r4 = 0;
    for(int i = 0, a; i < n; i += 1){
        cin >> a;
        mp[a] += 1;
        if(mp[a] % 2 == 0) r2 += 1;
        if(mp[a] % 4 == 0) r4 += 1;
    }
    int q;
    cin >> q;
    string s;
    for(int i = 0, a; i < q; i += 1){
        cin >> s >> a;
        if(s == "+"){
            mp[a] += 1;
            if(mp[a] % 2 == 0) r2 += 1;
            if(mp[a] % 4 == 0) r4 += 1;
        }
        else{
            if(mp[a] % 2 == 0) r2 -= 1;
            if(mp[a] % 4 == 0) r4 -= 1;
            mp[a] -= 1;
        }
        cout << (r2 >= 4 and r4 >= 1 ? "YES\n" : "NO\n");
    }
    return 0;
}