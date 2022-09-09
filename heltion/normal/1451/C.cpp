#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    for(cin >> _; _; _ -= 1){
        int n, k;
        string s, t;
        cin >> n >> k >> s >> t;
        vector<int> vs(26), vt(26);
        for(char c : s) vs[c - 'a'] += 1;
        for(char c : t) vt[c - 'a'] += 1;
        int ok = 1;
        for(int i = 0; i < 26; i += 1){
            while(i < 25 and vs[i] > vt[i] and vs[i] >= k){
                vs[i] -= k;
                vs[i + 1] += k;
            }
            if(vs[i] != vt[i]) ok = 0;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}