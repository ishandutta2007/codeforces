#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL k;
    cin >> k;
    string s = "codeforces";
    vector<int> v(10);
    for(int i = 0; ; i = (i + 1) % 10){
        LL p = 1;
        for(int x : v) p *= x;
        if(p >= k) break;
        v[i] += 1;
    }
    for(int i = 0; i < 10; i += 1)
        for(int j = 0; j < v[i]; j += 1) cout << s[i];
    return 0;
}