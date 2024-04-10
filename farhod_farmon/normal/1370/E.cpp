#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

using namespace std;

int n;
string s, t;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> s >> t;
        vector < int > v;
        for(int i = 0; i < n; i++){
                if(s[i] == t[i]){
                        continue;
                }
                v.push_back(s[i] - '0');
        }
        set < int > s[2];
        n = v.size();
        for(int i = 0; i < n; i++){
                s[v[i]].insert(i);
        }
        int res = 0;
        vector < int > g;
        while(!s[0].empty() && !s[1].empty()){
                res += 1;
                int i = 0;
                if(*s[1].begin() < *s[0].begin()){
                        i = 1;
                }
                g.clear();
                g.push_back(*s[i].begin());
                while(true){
                        int j = v[g.back()];
                        auto p = s[j ^ 1].lower_bound(g.back());
                        if(p == s[j ^ 1].end()){
                                break;
                        }
                        g.push_back(*p);
                }
                if(v[g.back()] == i){
                        g.pop_back();
                }
                for(int x: g){
                        s[v[x]].erase(x);
                }
        }
        if(!s[0].empty() || !s[1].empty()){
                cout << -1 << "\n";
                return 0;
        }
        cout << res << "\n";
}