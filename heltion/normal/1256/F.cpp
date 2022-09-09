#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    for(cin >> q; q; q -= 1){
        int n;
        string s, t, ss, tt;
        cin >> n >> s >> t;
        ss = s;
        tt = t;
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        if(ss != tt) cout << "NO\n";
        else{
            set<char> sc;
            for(char c : s) sc.insert(c);
            if(sc.size() < s.size()) cout << "YES\n";
            else{
                int p = 0;
                for(int i = 0; i < n; i += 1)
                    for(int j = i + 1; j < n; j += 1) if(s[i] > s[j]) p ^= 1;
                for(int i = 0; i < n; i += 1)
                    for(int j = i + 1; j < n; j += 1) if(t[i] > t[j]) p ^= 1;
                cout << (p ? "NO\n" : "YES\n");
            }
        }
    }
    return 0;
}