#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
string s[maxn], t[maxn];
bool used[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i += 1){
        cin >> s[i];
        t[i] = s[i];
        reverse(t[i].begin(), t[i].end());
    }
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i += 1) if(not used[i])
        for(int j = 0; j < n; j += 1)  if(not used[j] and i != j)
            if(s[i] == t[j]){
                v.push_back({i, j});
                used[i] = true;
                used[j] = true;
            }
    int p = -1;
    for(int i = 0; i < n; i += 1) if(not used[i] and s[i] == t[i]) p = i;
    if(~p){
        cout << (v.size() * 2 + 1) * m << "\n";
        string res;
        for(int i = 0; i < (int)v.size(); i += 1) res += s[v[i].first];
        cout << res << s[p];
        reverse(res.begin(), res.end());
        cout << res;
    }
    else{
        cout << v.size() * 2 * m << "\n";
        string res;
        for(int i = 0; i < (int)v.size(); i += 1) res += s[v[i].first];
        cout << res;
        reverse(res.begin(), res.end());
        cout << res;
    }
    return 0;
}