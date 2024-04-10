#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<LL> a[3];
    for(int i = 0, n; i < 3; i += 1){
        cin >> n;
        a[i].resize(n);
    }
    for(int i = 0; i < 3; i += 1){
        for(LL& x : a[i]) cin >> x;
        sort(a[i].begin(), a[i].end());
        partial_sum(a[i].begin(), a[i].end(), a[i].begin());
    }
    auto f = [](vector<LL> a, vector<LL> b, vector<LL> c)->LL{
        LL res = 0;
        res = max(res, b.back() - c.back());
        res = max(res, c.back() - b.back());
        res = max(res, b.back() - 2 * b[0] + c.back() - 2 * c[0]);
        return res + a.back();
    };
    cout << max({
        f(a[0], a[1], a[2]),
        f(a[1], a[0], a[2]),
        f(a[2], a[0], a[1])
    });
    return 0;
}