#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 55;
const long long mod = 998244353;

using namespace std;

int d[N][Q][Q];

vector < vector < int > > make(string s)
{
        vector < vector < int > > res((int)s.size() + 1);
        vector < string > pref(s.size() + 1);
        pref[0] = "";
        for(int i = 1; i <= s.size(); i++){
                pref[i] = pref[i - 1];
                pref[i] += s[i - 1];
        }
        for(auto &p: pref){
                reverse(p.begin(), p.end());
        }
        for(int i = 0; i <= s.size(); i++){
                res[i].resize(26);
                for(char c = 'a'; c <= 'z'; c++){
                        string cur = pref[i];
                        reverse(cur.begin(), cur.end());
                        cur += c;
                        reverse(cur.begin(), cur.end());
                        res[i][c - 'a'] = min(i + 1, (int)s.size());
                        while(res[i][c - 'a']){
                                bool good = true;
                                for(int j = 0; j < pref[res[i][c - 'a']].size(); j++){
                                        good &= pref[res[i][c - 'a']][j] == cur[j];
                                }
                                if(good){
                                        break;
                                } else{
                                        res[i][c - 'a'] -= 1;
                                }
                        }
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        string s, a, b;
        cin >> s >> a >> b;
        auto va = make(a);
        auto vb = make(b);
        for(int i = 0; i <= s.size(); i++){
                for(int j = 0; j <= a.size(); j++){
                        for(int h = 0; h <= b.size(); h++){
                                d[i][j][h] = -1e9;
                        }
                }
        }
        d[0][0][0] = 0;
        for(int i = 0; i < s.size(); i++){
                for(int j = 0; j <= a.size(); j++){
                        for(int h = 0; h <= b.size(); h++){
                                for(char c = 0; c < 26; c++){
                                        if(s[i] != '*' && s[i] != c + 'a'){
                                                continue;
                                        }
                                        int nj = va[j][c], nh = vb[h][c];
                                        d[i + 1][nj][nh] = max(d[i + 1][nj][nh], d[i][j][h] + (nj == a.size()) - (nh == b.size()));
                                }
                        }
                }
        }
        int res = -1e9;
        for(int i = 0; i <= a.size(); i++){
                for(int j = 0; j <= b.size(); j++){
                        res = max(res, d[s.size()][i][j]);
                }
        }
        cout << res << "\n";
}