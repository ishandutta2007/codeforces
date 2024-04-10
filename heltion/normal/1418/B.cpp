#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn + 1], l[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int i = 1; i <= n; i += 1) cin >> l[i];
        vector<int> v, w;
        for(int i = 1; i <= n; i += 1) if(not l[i]){
            v.push_back(a[i]);
            w.push_back(i);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < v.size(); i += 1) a[w[i]] = v[i];
        for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}