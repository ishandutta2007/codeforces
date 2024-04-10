#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 11;
const int Q = 111;

using namespace std;

int n;
string s[N];
int nxt[N][Q][52];
vector<int> v[N][52];
map<vector<int>, int> d;
map<vector<int>, vector<int>> p;

void solve()
{
        cin >> n;
        vector<int> g(n), ng(n);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < 52; j++){
                        v[i][j].clear();
                }
                cin >> s[i];
                for(int j = 0; j < s[i].size(); j++){
                        if(s[i][j] >= 'a' && s[i][j] <= 'z'){
                                v[i][s[i][j] - 'a'].push_back(j);
                        } else{
                                v[i][s[i][j] - 'A' + 26].push_back(j);
                        }
                }
                g[i] = -1;

                for(int j = 0; j < Q; j++){
                        for(int h = 0; h < 52; h++){
                                nxt[i][j][h] = Q;
                        }
                }
                for(int j = s[i].size() - 1; j >= 0; j--){
                        for(int h = 0; h < 52; h++){
                                nxt[i][j][h] = nxt[i][j + 1][h];
                        }
                        if(s[i][j] >= 'a' && s[i][j] <= 'z'){
                                nxt[i][j][s[i][j] - 'a'] = j;
                        } else{
                                nxt[i][j][s[i][j] - 'A' + 26] = j;
                        }
                }
        }
        d.clear();
        p.clear();
        d[g] = 0;
        vector<int> best;
        int res = 0;
        while(!d.empty()){
                g = d.begin()->fi;
                int cur = d.begin()->se;
                if(cur > res){
                        res = cur;
                        best = g;
                }
                d.erase(d.begin());
                for(int i = 0; i < 52; i++){
                        int good = 1;
                        for(int j = 0; j < n; j++){
                                if(nxt[j][g[j] + 1][i] == Q){
                                        good = 0;
                                        break;
                                }
                                ng[j] = nxt[j][g[j] + 1][i];
                        }
                        if(!good){
                                continue;
                        }
                        if(d.find(ng) == d.end() || cur + 1 > d[ng]){
                                d[ng] = cur + 1;
                                p[ng] = g;
                        }
                }
        }

        string shit = "";
        for(int i = 0; i < res; i++){
                shit += s[0][best[0]];
                best = p[best];
        }
        reverse(shit.begin(), shit.end());
        cout << res << "\n" << shit << "\n";
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
                solve();
        }
}