#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int tim;
int d[N];
int tin[N];
int tout[N];
int f[N][20];
vector < int > v[N];

void dfs(int x, int p)
{
        tin[x] = ++tim;
        f[x][0] = p;
        for(int i = 1; i < 20; i++){
                f[x][i] = f[f[x][i - 1]][i - 1];
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                d[y] = d[x] + 1;
                dfs(y, x);
        }
        tout[x] = tim;
}

bool isp(int x, int y)
{
        return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
        if(isp(x, y)){
                return x;
        }
        if(isp(y, x)){
                return y;
        }
        for(int i = 19; i >= 0; i--){
                if(!isp(f[x][i], y)){
                        x = f[x][i];
                }
        }
        return f[x][0];
}

int dir(int x)
{
        cout << "s " << x << endl;
        cin >> x;
        return x;
}

int dist(int x)
{
        cout << "d " << x << endl;
        cin >> x;
        return x;
}

vector < int > ch;

void go(int x, int p, int len)
{
        if(!len){
                ch.push_back(x);
                return;
        }
        for(int y: v[x]){
                if(y != p){
                        go(y, x, len - 1);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        int len = dist(1), cur = 1;
        while(len > 0){
                ch.clear();
                go(cur, f[cur][0], len);
                assert(!ch.empty());
                if(ch.size() == 1){
                        cur = ch[0];
                        break;
                }
                int f = dist(ch[ch.size() / 2]);
                f = len - (2 * len - f) / 2;
                int p = ch[ch.size() / 2];
                for(int i = 0; i < 20; i++){
                        if(f & (1 << i)){
                                p = ::f[p][i];
                        }
                }
                if(p == ch[ch.size() / 2]){
                        p = ::f[p][0];
                }
                int nxt = dir(p);
                len -= d[nxt] - d[cur];
                cur = nxt;
        }
        cout << "! " << cur << endl;
}