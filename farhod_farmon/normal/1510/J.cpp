#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 300100;

vector < int > solve(vector < pair < int, int > > g, int dif, int cur)
{
        vector < int > res;

        int rem = cur - dif + 1;

        if(rem == 2){
                return {};
        } else if(rem % 2 == 0){
                if(dif < 2){
                        return {};
                }
                res.push_back(2);
                rem -= 3;
        }
        while(rem > 1){
                if(dif < 1){
                        return {};
                }
                res.push_back(1);
                rem -= 2;
        }

        for(int i = 0; i < g.size(); i++){
                auto p = g[i];

                res.push_back(p.fi + dif);

                int rem = p.se - dif + (i + 1 == g.size());
                if(rem < 1 || rem == 2){
                        return {};
                } else if(rem % 2 == 0){
                        if(dif < 2){
                                return {};
                        }
                        res.push_back(2);
                        rem -= 3;
                }
                while(rem > 1){
                        if(dif < 1){
                                return {};
                        }
                        rem -= 2;
                        res.push_back(1);
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

        string s;
        cin >> s;
        int cnt = 0;
        for(char c: s){
                cnt += (c == '#');
        }
        if(cnt == 0){
                cout << 0 << "\n";
                return 0;
        }


        int dif = 0, n = s.size();
        while(s[dif] == '_'){
                dif += 1;
        }

        int x = 0, y = 0;
        vector < int > res;
        vector < pair < int, int > > g;
        for(int i = dif; i < n; i++){
                if(s[i] == '#'){
                        if(y > 0){
                                g.push_back({x, y});
                                x = y = 0;
                        }
                        x += 1;
                } else{
                        y += 1;
                }
        }
        g.push_back({x, y});

        for(int can: {0, 1, 2, 3, 4, 5, dif}){
                if(can > dif){
                        continue;
                }
                res = solve(g, can, dif);
                if(!res.empty()){
                        break;
                }
        }

        if(res.empty()){
                cout << -1 << "\n";
                return 0;
        }

        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}