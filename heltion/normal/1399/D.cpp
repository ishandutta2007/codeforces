#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        vector<int> ans;
        cin >> s >> s;
        set<int> ss[2];
        int k = 0;
        for(char c : s){
            if(ss[(c - '0') ^ 1].empty()) ss[(c - '0') ^ 1].insert(k += 1);
            int a = *ss[(c - '0') ^ 1].begin();
            ans.push_back(a);
            ss[(c - '0') ^ 1].erase(a);
            ss[c - '0'].insert(a);
        }
        cout << k << "\n";
        for(int a : ans) cout << a << " ";
        cout << "\n";
    }
    return 0;
}