#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long mx = 1e9;
long long best[N][26];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                string s;
                cin >> s;
                for(int j = 0; j < 26; j++){
                        best[i][j] = min(best[i - 1][j], 1ll);
                        best[i - 1][j] = min(best[i - 1][j], mx);
                }
                for(int j = 0, cnt = 1; j < s.size(); j++){
                        if(j + 1 < s.size() && s[j] == s[j + 1]){
                                cnt++;
                                continue;
                        }
                        best[i][s[j] - 'a'] = max(best[i][s[j] - 'a'], 1ll * cnt);
                        cnt = 1;
                }
                long long l = 0;
                while(l < s.size() && s[l] == s[0]){
                        l++;
                }
                if(l == s.size()){
                        char c = s[0] - 'a';
                        best[i][c] = max(best[i][c], (best[i - 1][c] + 1) * l + best[i - 1][c]);
                        continue;
                }
                char c = s[0] - 'a';
                best[i][c] = max(best[i][c], min(best[i - 1][c], 1ll) + l);
                c = s[s.size() - 1];
                int fi = l;
                l = 0;
                while(s[s.size() - 1 - l] == c){
                        l++;
                }
                if(c == s[0]){
                        l += fi;
                }
                c -= 'a';
                best[i][c] = max(best[i][c], min(best[i - 1][c], 1ll) + l);
        }
        long long res = 0;
        for(int i = 0; i < 26; i++){
                res = max(res, best[n][i]);
        }
        cout << res << "\n";
}