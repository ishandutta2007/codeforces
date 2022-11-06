#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000 + 1;
int a[maxn];
vector<int> p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        multiset<int> ms;
        set<pair<int, int>> sp;
        for(int i = 1; i <= n; i += 1) p[i].clear();
        for(int i = 1; i <= n; i += 1){
            cin >> a[i];
            p[a[i]].push_back(i);
            ms.insert(a[i]);
        }
        string ans;
        for(int i = 1, L = 1, R = n; i < n; i += 1){
            if(*ms.begin() == i) ans.push_back('1');
            else ans.push_back('0');
            if(p[i].size() != 1) break;
            ms.erase(i);
            if(p[i][0] == L) L += 1;
            else if(p[i][0] == R) R -= 1;
            else break;
        }
        while((int)ans.size() < n - 1) ans.push_back('0');
        int ok = 1;
        for(int i = 1; i <= n; i += 1) ok &= p[i].size() == 1;
        ans.push_back(ok + '0');
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}