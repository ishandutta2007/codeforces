#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int mod = 1e9 + 7;

using namespace std;

int get(set < pair < int, int > > &s, int l, int r)
{
        if(s.empty()){
                return 0;
        }
        int res = 0;
        auto p = s.lower_bound({r + 1, 0});
        while(p != s.begin()){
                p--;
                if(p->se < l){
                        break;
                }
                int tl = p->fi, tr = p->se;
                s.erase(p);
                res += min(tr, r) - max(tl, l) + 1;
                if(tl < l){
                        s.insert({tl, l - 1});
                }
                if(r < tr){
                        s.insert({r + 1, tr});
                }
                if(s.empty()){
                        break;
                }
                p = s.lower_bound({r + 1, 0});
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
                int n, q;
                string s, t;
                cin >> n >> q >> s >> t;
                vector < pair < int, int > > v(q);
                for(int i = 0; i < q; i++){
                        cin >> v[i].fi >> v[i].se;
                        v[i].fi -= 1;
                        v[i].se -= 1;
                }
                int res = 1;
                set < pair < int, int > > A, B;
                for(int i = 0, j = 0; i < n; i++){
                        if(i == n - 1 || t[i] != t[i + 1]){
                                if(t[i] == '0'){
                                        A.insert({j, i});
                                } else{
                                        B.insert({j, i});
                                }
                                j = i + 1;
                        }
                }
                for(int i = q - 1; i >= 0; i--){
                        int x = get(A, v[i].fi, v[i].se);
                        int y = get(B, v[i].fi, v[i].se);
                        if(x == y){
                                res = 0;
                                break;
                        } else if(x < y){
                                B.insert(v[i]);
                        } else{
                                A.insert(v[i]);
                        }
                }
                for(auto p: A){
                        for(int i = p.fi; i <= p.se; i++){
                                t[i] = '0';
                        }
                }
                for(auto p: B){
                        for(int i = p.fi; i <= p.se; i++){
                                t[i] = '1';
                        }
                }
                res &= (s == t);
                cout << (res ? "YES" : "NO") << "\n";
        }
}