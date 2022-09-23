#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
bool dead[N];
pair < int, int > a[N];

int ori(pair < int, int > a, pair < int, int > b, pair < int, int > c)
{
        long long f = 1ll * (b.fi - a.fi) * (c.se - a.se) - 1ll * (b.se - a.se) * (c.fi - a.fi);
        if(f < 0){
                return 1; // clock
        } else if(f > 0){
                return -1; // anti
        }
        return 0;
}

int root;

bool cmp(int x, int y)
{
        return ori(a[root], a[x], a[y]) == 1;
}

vector < int > make()
{
        int h = -1;
        for(int i = 1; i <= n; i++){
                if(dead[i]){
                        continue;
                }
                if(h == -1 || a[i] < a[h]){
                        h = i;
                }
        }
        vector < int > res;
        res.push_back(h);
        vector < int > v;
        for(int i = 1; i <= n; i++){
                if(dead[i] || i == h){
                        continue;
                }
                v.push_back(i);
        }
        root = h;
        sort(v.begin(), v.end(), cmp);
        for(int x: v){
                while(res.size() > 1 && ori(a[res[res.size() - 2]], a[res[res.size() - 1]], a[x]) == -1){
                        res.pop_back();
                }
                res.push_back(x);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("teleports.in", "r", stdin);
        //freopen("teleports.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
        }
        string s;
        cin >> s;

        auto v = make();
        vector < int > res;
        int di;
        if(s[0] == 'L'){
                di = -1;
                dead[v[1]] = true;
                res.push_back(v[1]);
                res.push_back(v[0]);
        } else{
                di = 1;
                dead[v[0]] = true;
                res.push_back(v[0]);
                res.push_back(v[1]);
        }
        for(int i = 0; i < s.size(); i++){
                v = make();
                if(i + 1 < s.size() && s[i] != s[i + 1]){
                        di *= -1;
                }
                dead[res.back()] = true;
                int h = 0;
                for(int j = 0; j < v.size(); j++){
                        if(v[j] == res.back()){
                                h = j;
                        }
                }
                h = (h + di + v.size()) % (int)v.size();
                res.push_back(v[h]);
        }
        for(int x: res){
                cout << x << " ";
        }
}