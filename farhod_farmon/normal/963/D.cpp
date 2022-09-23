#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int sz;
int p[N];
int id[N];
int fi[N];
int ch[N];
int link[N];
int f[N][26];

int go(int x, int c);

int get(int x)
{
        if(link[x] != -1){
                return link[x];
        }
        if(x == 0 || p[x] == 0){
                link[x] = 0;
        }
        else{
                link[x] = go(get(p[x]), ch[x]);
        }
        return link[x];
}

int go(int x, int c)
{
        if(f[x][c] != -1){
                return f[x][c];
        }
        if(x == 0){
                f[x][c] = 0;
        }
        else{
                f[x][c] = go(get(x), c);
        }
        return f[x][c];
}

string s;
int n;
int k[N];
int l[N];
vector < int > v[N];

int get_fi(int x)
{
        if(fi[x] != -1){
                return fi[x];
        }
        if(id[x] > 0){
                return fi[x] = x;
        }
        return fi[x] = get_fi(get(x));
}

void solve()
{
        cin >> s >> n;
        for(int i = 0; i < 26; i++){
                f[0][i] = -1;
        }
        for(int i = 1; i <= n; i++){
                string t;
                cin >> k[i] >> t;
                l[i] = t.size();
                int x = 0;
                for(int j = 0; j < t.size(); j++){
                        t[j] -= 'a';
                        if(f[x][t[j]] == -1){
                                f[x][t[j]] = ++sz;
                                p[sz] = x;
                                ch[sz] = t[j];
                                fi[sz] = link[sz] = id[sz] = -1;
                                for(int j = 0; j < 26; j++){
                                        f[sz][j] = -1;
                                }
                        }
                        x = f[x][t[j]];
                }
                id[x] = i;
        }
        int x = 0;
        for(int i = 0; i < s.size(); i++){
                x = go(x, s[i] - 'a');
                for(int j = get_fi(x); j > 0; j = get_fi(get(j))){
                        v[id[j]].push_back(i);
                }
        }
        for(int i = 1; i <= n; i++){
                if(v[i].size() < k[i]){
                        cout << -1 << "\n";
                        continue;
                }
                int ans = 1e9;
                for(int j = k[i] - 1; j < v[i].size(); j++){
                        ans = min(ans, v[i][j] - v[i][j - k[i] + 1]);
                }
                cout << ans + l[i] << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}