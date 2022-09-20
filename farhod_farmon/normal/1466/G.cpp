#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const int mod = 1e9 + 7;

using namespace std;

int pw(int x, int y, int mod)
{
        int res = 1;
        while(y > 0){
                if(y & 1){
                        res = 1ll * res * x % mod;
                }
                y /= 2;
                x = 1ll * x * x % mod;
        }
        return res;
}

pair < int, int > M;

void add(int &x, int y, int mod)
{
        x += y;
        if(x >= mod){
                x -= mod;
        } else if(x < 0){
                x += mod;
        }
}

pair < int, int > operator *(const pair < int, int > x, const pair < int, int > y)
{
        return {1ll * x.fi * y.fi % M.fi, 1ll * x.se * y.se % M.se};
}

pair < int, int > operator +(const pair < int, int > x, const pair < int, int > y)
{
        pair < int, int > res = x;
        add(res.fi, y.fi, M.fi);
        add(res.se, y.se, M.se);
        return res;
}

pair < int, int > operator +(const pair < int, int > x, const int y)
{
        return x + make_pair(y, y);
}

pair < int, int > operator *(const pair < int, int > x, const int y)
{
        return x * make_pair(y, y);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool isp(long long x)
{
        for(long long i = 2; i * i <= x; i++){
                if(x % i == 0){
                        return false;
                }
        }
        return true;
}

int n;
int q;
int p[N];
int rev[N];
int f[N][26];
string s, t;

pair < int, int > P[Q];
pair < int, int > pref[Q];
pair < int, int > suf[Q];

void init()
{
        p[0] = 1;
        for(int i = 1; i < N; i++){
                p[i] = p[i - 1];
                add(p[i], p[i], mod);
        }
        rev[N - 1] = pw(p[N - 1], mod - 2, mod);
        for(int i = N - 2; i >= 0; i--){
                rev[i] = 1ll * rev[i + 1] * 2 % mod;
        }

        M.fi = 1e9 + 321 + rng() % 321789;
        M.se = 1e9 + 32131 + rng() % 321789;
        while(!isp(M.fi)){
                M.fi += 1;
        }
        while(!isp(M.se)){
                M.se += 1;
        }

        P[0] = {1, 1};
        P[1] = {1007, 31};
        for(int i = 2; i < Q; i++){
                P[i] = P[i - 1] * P[1];
        }
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        init();

        cin >> n >> q >> s >> t;

        //while(t.size() <= n) t += "a";

        vector < int > v = {0};
        for(int i = 1; i < t.size() && v.size() < Q - 2; i++){
                int g = v.size();
                v.push_back(i);
                for(int j = 0; j < g && v.size() < Q - 2; j++){
                        v.push_back(v[j]);
                }
        }

        for(int i = 0; i < v.size(); i++){
                pref[i + 1] = pref[i] + (P[i] * (t[v[i]] - 'a' + 1));
        }


        for(int i = 0; i < t.size(); i++){
                for(int j = 0; j < 26; j++){
                        f[i + 1][j] = f[i][j];
                }
                add(f[i + 1][t[i] - 'a'], rev[i + 1], mod);
        }

        for(int i = 1; i <= q; i++){
                string w;
                int x;
                cin >> x >> w;

                int g = w.size();
                vector < int > H(g, 1);
                for(int j = 0; j < g; j++){
                        for(int h = 0; h < s.size() && j + h < g; h++){
                                if(s[h] != w[j + h]){
                                        H[j] = 0;
                                        break;
                                }
                        }
                }

                vector < int > V;
                vector < pair < int, int > > h1, h2;

                int res = 0;

                for(int j = 0, st; j <= s.size(); j++){
                        V.clear();
                        st = 0;
                        for(int h = j; h < s.size() && st < g; h++){
                                if(s[h] != w[st]){
                                        st = -1;
                                        break;
                                }
                                st += 1;
                        }
                        if(st < 0){
                                continue;
                        }
                        if(st < g){
                                V.push_back(w[st] - 'a' + 1);
                                st += 1;
                        }
                        while(st < g){
                                if(!H[st]){
                                        st = -1;
                                        break;
                                }
                                st += s.size();
                                if(st < g){
                                        V.push_back(w[st] - 'a' + 1);
                                        st += 1;
                                }
                        }
                        if(st < 0){
                                continue;
                        }

                        if(V.empty()){
                                add(res, p[x], mod);
                                continue;
                        }

                        h1.resize((int)V.size() + 1);
                        h2.resize((int)V.size() + 1);

                        h1[0] = {0, 0};
                        h2[V.size()] = {0, 0};
                        for(int j = V.size() - 1; j >= 0; j--){
                                h2[j] = h2[j + 1] * P[1];
                                h2[j] = h2[j] + V[j];
                        }
                        for(int j = 0; j < V.size(); j++){
                                h1[j + 1] = h1[j] * P[1];
                                h1[j + 1] = h1[j + 1] + V[j];
                        }


                        for(int j = 0; j < V.size(); j++){
                                if(h1[j] != pref[j] || h2[j + 1] != pref[V.size() - j - 1]){
                                        continue;
                                }

                                int mx = 1, shit = max(j, (int)V.size() - j - 1);
                                while(p[mx - 1] - 1 < shit){
                                        mx += 1;
                                }
                                if(mx > x){
                                        continue;
                                }

                                int dif = f[x][V[j] - 1];
                                dif -= f[mx - 1][V[j] - 1];
                                if(dif < 0){
                                        dif += mod;
                                }
                                add(res, 1ll * p[x] * dif % mod, mod);
                        }
                }
                cout << res << "\n";
        }

}