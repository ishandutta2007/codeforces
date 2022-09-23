#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int mod = 1e9 + 7;

using namespace std;

string s;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

void rec()
{
        set < string > S;
        S.insert(s);
        while(true){
                int l = S.size();
                vector < string > v;
                for(auto s: S){
                        if(s.size() == 1) continue;
                        string t = "";
                        for(int i = 1; i < s.size(); i++){
                                string nt = t;
                                nt += max(s[i - 1], s[i]);
                                for(int j = i + 1; j < s.size(); j++) nt += s[j];
                                v.push_back(nt);
                                t += s[i - 1];
                        }
                }
                for(auto s: v) S.insert(s);
                if(S.size() == l) break;
        }
        cout << S.size() << " ";
        int A = 0, B = 0;
        for(auto s: S){
                if(s.back() == '0') A += 1;
                else B += 1;
        }
        cout <<A << " " << B << "\n";
        for(auto s: S) cout << s << "\n";
}

int r[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> s;
        vector < pair < int, int > > v;
        for(char c: s){
                int x = c - '0';
                if(v.empty() || v.back().fi != x){
                        v.push_back({x, 1});
                } else{
                        v.back().se += 1;
                }
        }


        int n = v.size();
        vector < int > d(n + 2, 0);

        if(n == 1){
                cout << v[0].se << "\n";
                return 0;
        }
        int A = 1;
        if(v[0].fi == 0){
                d[0] = v[0].se;
                add(A, d[0]);
        } else{
                d[0] = v[0].se;
        }

        vector < int > g;
        for(int i = n - 1; i >= 0; i--){
                r[i] = -1;
                if(v[i].fi) continue;
                while(!g.empty() && v[i].se >= v[g.back()].se) g.pop_back();
                if(!g.empty()) r[i] = g.back();
                g.push_back(i);
        }

        for(int i = 1; i < n; i++){
                if(v[i].fi == 0){
                        add(d[i], 1ll * d[i - 1] * v[i].se % mod);
                        add(A, d[i]);
                        if(r[i] != -1){
                                //cout << d[r[i]] << d[i] * (v[r[i]].se - v[i].se) << endl;
                                add(d[r[i]], d[i - 1] * 1ll * (v[r[i]].se - v[i].se) % mod);
                                int j = r[i];
                                while(r[j] != -1){
                                        add(d[r[j]], d[i - 1] * 1ll * (v[r[j]].se - v[j].se) % mod);
                                        j = r[j];
                                }
                        }
                } else{
                        add(d[i], 1ll * A * v[i].se % mod);
                }
        }
        //cout <<
        int res = 0;
        //cout <<
        //cout << res << endl;
        int B = 0;
        for(int i = 0; i < n; i++){
                if(v[i].fi == 1){
                        add(res, d[i]);
                        if(v.back().fi == 0){
                                add(res, 1ll * d[i] * v.back().se % mod);
                        }
                }
        }
        cout << res << "\n";
        //cout << res << " " << B << " " << res - B << "\n";
        //rec();
}