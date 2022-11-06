#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
using LL = long long;
LL a[6], b[maxn];
int k[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 0; i < 6; i += 1) cin >> a[i];
    sort(a, a + 6);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1) cin >> b[i];
    vector<LL> v;
    set<pair<LL, int>> s;
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < 6; j += 1) v.push_back(b[i] - a[j]);
        k[i] = 5;
        s.insert({b[i] - a[k[i]], i});
    }
    LL ans = 1E18;
    sort(v.begin(), v.end());
    for(LL x : v){
        while(s.begin()->first < x){
            auto i = s.begin()->second;
            s.erase(s.begin());
            if(k[i] == 0){
                cout << ans;
                return 0;
            }
            k[i] -= 1;
            s.insert({b[i] - a[k[i]], i});
        }
        ans = min(ans, prev(s.end())->first - x);
    }
    cout << ans;
    return 0;
}