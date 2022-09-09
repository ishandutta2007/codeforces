#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int k;
    cin >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> par(1 << k), L(1 << k), R(1 << k), f(1 << k);
    for(int i = 1, x = 1, y = (1 << (k - 1)) + 1; i < k; i += 1){
        for(int j = 0; j < (1 << (k - i)); j += 1){
            par[j + x] = j / 2 + y;
            (j & 1 ? R : L)[j / 2  + y] = j + x;
        }
        x = y;
        y += (1 << (k - i - 1));
    }
    auto up = [&](int i){
        f[i] = 0;
        if(i <= (1 << (k - 1))) f[i] = 1 + (s[i] == '?');
        else{
            if(s[i] != '1') f[i] += f[L[i]];
            if(s[i] != '0') f[i] += f[R[i]];
        }
    };
    for(int i = 1; i < (1 << k); i += 1) up(i);
    int q;
    for(cin >> q; q; q -= 1){
        int p;
        string c;
        cin >> p >> c;
        for(s[p] = c[0]; p; p = par[p]) up(p);
        cout << f.back() << "\n";
    }
    return 0;
}