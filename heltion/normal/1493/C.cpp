#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setfill('0');
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n % k){
            cout << -1 << "\n";
            continue;
        }
        vector<int> cnt(26);
        for(char c : s) cnt[c - 'a'] += 1;
        int pf = 1;
        for(int x : cnt) if(x % k) pf = 0;
        if(pf){
            cout << s << "\n";
            continue;
        }
        for(int i = n - 1, done = 0; i >= 0 and not done; i -= 1){
            cnt[s[i] - 'a'] -= 1;
            for(int j = s[i] - 'a' + 1; j < 26 and not done; j += 1){
                cnt[j] += 1;
                int rm = 0;
                for(int x : cnt) rm += (k - x % k) % k;
                if(rm < n - i){
                    done = 1;
                    cout << s.substr(0, i);
                    cout << char(j + 'a');
                    for(int p = 0; p < n - i - 1 - rm; p += 1) cout << 'a';
                    for(int p = 0; p < 26; p += 1)
                        while(cnt[p] ++ % k) cout << char(p + 'a');
                    cout << '\n';
                }
                cnt[j] -= 1;
            }
        }
    }
    return 0;
}