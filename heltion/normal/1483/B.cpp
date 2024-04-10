#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        set<int> s, t;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        for(int i = 1; i <= n; i += 1) t.insert(i);
        for(int i = 1; i <= n; i += 1){
            if(i == 1){
                if(gcd(a[1], a[n]) == 1) s.insert(1);
            }
            else if(gcd(a[i], a[i - 1]) == 1) s.insert(i);
        }
        int p = 1;
        vector<int> ans;
        while(not s.empty()){
            auto it = s.upper_bound(p);
            if(it == s.end()) p = *s.begin();
            else p = *it;
            ans.push_back(p);
            t.erase(p);
            if(t.empty()) break;
            int nxt = 0;
            it = t.upper_bound(p);
            if(it == t.end()) nxt = *t.begin();
            else nxt = *it;
            int pre = 0;
            if(it == t.begin()) pre = *t.rbegin();
            else pre = *prev(it);
            s.erase(p);
            s.erase(nxt);
            if(gcd(a[nxt], a[pre]) == 1) s.insert(nxt);
            it = t.upper_bound(p);
            if(it == t.end()) p = *t.begin();
            else p = *it;
        }
        cout << ans.size() << ' ';
        for(int x : ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}