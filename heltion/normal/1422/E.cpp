#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v, w;
    vector<pair<int, string>> ans;
    for(int i = n - 1; i >= 0; i -= 1){
        if(not v.empty() and s[v.back()] == s[i] and v.back() == i + 1 and (w.back() == -1 or s[i] > s[v[w.back()]])){
            v.pop_back();
            w.pop_back();
        }
        else{
            if(v.empty()) w.push_back(-1);
            else if(s[v.back()] == s[i]) w.push_back(w.back());
            else w.push_back(v.size() - 1);
            v.push_back(i);
        }
        ans.push_back({v.size(), ""});
        if(v.size() <= 10)
            for(int i = (int)v.size() - 1; i >= 0; i -= 1) ans.back().second.push_back(s[v[i]]);
        else{
            for(int i = (int)v.size() - 1; i >= (int)v.size() - 5; i -= 1) ans.back().second.push_back(s[v[i]]);
            ans.back().second = ans.back().second + "..." + s[v[1]] + s[v[0]];
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
    return 0;
}