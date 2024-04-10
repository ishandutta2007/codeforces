#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500000;
int mp[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i += 1){
        for(int j = i * 2; j <= n; j += i)
            mp[j] = i;
        v.push_back(mp[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i += 1) cout << v[i] << " ";
    return 0;
}