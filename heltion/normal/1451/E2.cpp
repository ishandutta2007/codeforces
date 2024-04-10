#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 20;
int x[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i += 1){
        cout << "XOR " << 1 << " " << i << endl;
        cin >> x[i];
    }
    for(int i = 2; i <= n; i += 1){
        if(x[i] == 0){
            cout << "AND " << 1 << " " << i << endl;
            cin >> x[1];
            cout << "! " << x[1];
            for(int i = 2; i <= n; i += 1) cout << " " << (x[1] ^ x[i]);
            return 0;
        }
    }
    map<int, int> mp;
    for(int i = 2; i <= n; i += 1){
        if(mp.count(x[i])){
            int j = mp[x[i]];
            cout << "AND " << j << " " << i << endl;
            cin >> x[1];
            x[1] ^= x[i];
            cout << "! " << x[1];
            for(int k = 2; k <= n; k += 1) cout << " " << (x[1] ^ x[k]);
            return 0;
        }
        mp[x[i]] = i;
    }
    int g = 0, h = 0, fg, fh;
    for(int i = 2; i <= n; i += 1){
        if(x[i] == 1) g = i;
        if(x[i] == 2) h = i;
    }
    cout << "AND 1 " << g << endl;
    cin >> fg;
    cout << "AND 1 " << h << endl;
    cin >> fh;
    x[1] = fg | fh;
    cout << "! " << x[1];
    for(int k = 2; k <= n; k += 1) cout << " " << (x[1] ^ x[k]);
    return 0;
}