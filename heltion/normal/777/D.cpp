#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> vs(n);
    for(auto& s : vs) cin >> s;
    for(int i = n - 2; i >= 0; i -= 1){
        int k = 0;
        for(int j = 1; j < vs[i].size() and vs[i + 1].size(); j += 1)
            if(vs[i][j] != vs[i + 1][j]){
                k = j;
                break;
            }
        if(vs[i][k] > vs[i + 1][k]) vs[i].resize(k);
        else if(k == 0 and vs[i].size() > vs[i + 1].size()) vs[i].resize(vs[i + 1].size());
    }
    for(auto s : vs) cout << s << "\n";
    return 0;
}