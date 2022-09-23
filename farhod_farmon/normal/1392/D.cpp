#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int inf = 1e9;
int d[N], n;
string s, t;
vector < string > can;

int solve(string s)
{
        s = "#" + s;
        d[1] = inf;
        int cnt = 0;
        for(int i = 2; i <= n; i++){
                d[i] = inf;
                for(auto &t: can){
                        if(t.size() > i){
                                continue;
                        }
                        cnt = 0;
                        for(int j = 0; j < t.size(); j++){
                                if(s[i - t.size() + j + 1] != t[j]){
                                        cnt += 1;
                                }
                        }
                        d[i] = min(d[i], d[i - t.size()] + cnt);
                }
        }
        return d[n];
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        can.push_back("RL");
        can.push_back("RRL");
        can.push_back("RLL");
        can.push_back("RRLL");

        int T;
        cin >> T;
        while(T--){
                cin >> n >> s;
                int res = inf;
                for(int it = 0; it < 4; it++){
                        res = min(res, solve(s));
                        t = "";
                        for(int j = 1; j < n; j++){
                                t += s[j];
                        }
                        t += s[0];
                        s = t;
                }
                cout << res << "\n";
        }
}