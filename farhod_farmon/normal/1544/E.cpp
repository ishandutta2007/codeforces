#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

string solve(string s)
{
        vector < int > c(26, 0);
        int cnt = 0;
        for(char x : s){
                c[x - 'a'] += 1;
                cnt += (x == s[0]);
        }

        if(cnt == s.size()){
                return s;
        }

        int h = -1;
        vector < pair < int, int > > v;
        for(int i = 0; i < 26; i++){
                if(c[i] > 0){
                        v.push_back({i, c[i]});
                }
                if(c[i] == 1){
                        h = i;
                        break;
                }
        }

        if(h != -1){
                string res = "";
                res += string(1, 'a' + h);
                c[h] = 0;
                for(int i = 0; i < 26; i++){
                        if(c[i] > 0){
                                res += string(c[i], 'a' + i);
                        }
                }
                return res;
        }

        int n = s.size();
        string res = "";
        if(n - v[0].se >= v[0].se - 2){
                res += string(2, 'a' + v[0].fi);
                v[0].se -= 2;

                for(int i = 1; i < v.size(); i++){
                        for(int j = 0; j < v[i].se; j++){
                                res += string(1, 'a' + v[i].fi);
                                if(v[0].se){
                                        res += string(1, 'a' + v[0].fi);
                                        v[0].se -= 1;
                                }
                        }
                }
        } else{
                if(v.size() > 2){
                        res += string(1, 'a' + v[0].fi);
                        res += string(1, 'a' + v[1].fi);
                        res += string(v[0].se - 1, 'a' + v[0].fi);
                        res += string(1, 'a' + v[2].fi);
                        res += string(v[1].se - 1, 'a' + v[1].fi);
                        res += string(v[2].se - 1, 'a' + v[2].fi);
                        for(int i = 3; i < v.size(); i++){
                                res += string(v[i].se, 'a' + v[i].fi);
                        }
                } else{
                        res += string(1, 'a' + v[0].fi);
                        res += string(1, 'a' + v[1].fi);
                        res += string(v[1].se - 1, 'a' + v[1].fi);
                        res += string(v[0].se - 1, 'a' + v[0].fi);
                }
        }

        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                string s;
                cin >> s;
                cout << solve(s) << "\n";
        }
}