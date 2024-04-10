#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 660;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int c[N];
vector < int > v[N];

int ask(vector < int > g)
{
        if(g.size() <= 1){
                return 0;
        }
        cout << "? " << g.size() << endl;
        for(int x: g){
                cout << x << " ";
        }
        cout << endl;
        int gg;
        cin >> gg;
        return gg;
}

int get(int x)
{
        vector < int > g;
        for(int i = 1; i <= n; i++){
                if(c[i]){
                        continue;
                }
                g.push_back(i);
        }
        if(g.empty()){
                return -1;
        }
        int g1 = ask(g);
        g.push_back(x);
        int g2 = ask(g);
        g.pop_back();
        if(g1 == g2){
                return -1;
        }
        while(g.size() > 1){
                int m = (int)g.size() / 2;
                vector < int > ng;
                for(int i = 0; i < m; i++){
                        ng.push_back(g[g.size() - i - 1]);
                }
                int g1 = ask(ng);
                ng.push_back(x);
                int g2 = ask(ng);
                ng.pop_back();
                if(g1 == g2){
                        for(int i = 0; i < m; i++){
                                g.pop_back();
                        }
                }
                else{
                        g = ng;
                }
        }
        return g[0];
}

void dfs(int x, int g)
{
        c[x] = g;
        while(true){
                int y = get(x);
                if(y == -1){
                        break;
                }
                v[x].push_back(y);
                v[y].push_back(x);
                dfs(y, 3 - g);
        }
}

vector < int > path;

void go(int x, int p, int s)
{
        path.push_back(x);
        if(path.back() == s){
                return;
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                go(y, x, s);
        }
        if(path.back() == s){
                return;
        }
        path.pop_back();
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                if(c[i] == 0){
                        dfs(i, 1);
                }
        }
        vector < int > v1, v2;
        for(int i = 1; i <= n; i++){
                if(c[i] == 1){
                        v1.push_back(i);
                }
                else{
                        v2.push_back(i);
                }
        }
        int g1 = ask(v1);
        int g2 = ask(v2);
        if(g1 == 0 && g2 == 0){
                cout << "Y" << endl;
                cout << v1.size() << endl;
                for(int x: v1){
                        cout << x << " ";
                }
                cout << endl;
                return;
        }
        if(g2 > 0){
                v1 = v2;
        }
        for(int x: v1){
                c[x] = 0;
        }
        for(int x: v1){
                c[x] = 1;
                int y = get(x);
                c[x] = 0;
                if(y == -1){
                        continue;
                }
                path.clear();
                go(x, x, y);
                cout << "N" << endl;
                cout << path.size() << endl;
                for(int f: path){
                        cout << f << " ";
                }
                cout << endl;
                return;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}