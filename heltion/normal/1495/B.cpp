#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int& x : p) cin >> x;
    vector<int> pre(n), suf(n);
    for(int i = 1; i < n; i += 1)
        if(p[i] > p[i - 1]) pre[i] = pre[i - 1] + 1;
    for(int i = n - 2; i >= 0; i -= 1)
        if(p[i] > p[i + 1]) suf[i] = suf[i + 1] + 1;
    vector<int> peek;
    for(int i = 0; i < n; i += 1)
        if(pre[i] and suf[i]) peek.push_back(i);
    int mx = -1;
    for(int x : peek) if(mx == -1 or max(pre[x], suf[x]) > max(pre[mx], suf[mx])) mx = x;
    //for(int x : peek) cout << x << " " << pre[x] << " " << suf[x] << "\n";
    if(mx == -1){
        cout << 0;
        return 0;
    }
    int ok = 1; 
    for(int x = 0; x < n; x += 1) if(x != mx and (pre[x] >= max(pre[mx], suf[mx]) or suf[x] >= max(pre[mx], suf[mx]))) ok = 0;
    if(not ok or pre[mx] - (pre[mx] % 2 == 0) >= suf[mx] or suf[mx] - (suf[mx] % 2 == 0) >= pre[mx]) cout << "0";
    else cout << 1;
    return 0;
}