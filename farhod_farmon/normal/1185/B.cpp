#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

vector < pair < char, int > > get(string s)
{
        vector < pair < char, int > > res;
        for(int i = 0, j = 0; i < s.size(); i++){
                j += 1;
                if(i + 1 < s.size() && s[i] == s[i + 1]){
                        continue;
                }
                res.push_back({s[i], j});
                j = 0;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                string s, t;
                cin >> s >> t;
                auto a = get(s), b = get(t);
                int res = 0;
                if(a.size() == b.size()){
                        res = 1;
                        for(int i = 0; i < a.size(); i++){
                                if(a[i].fi != b[i].fi) res = 0;
                                else if(a[i].se > b[i].se) res = 0;
                        }
                }
                if(res){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}