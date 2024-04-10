#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n, k;
int c[N];
int p[N];
bool st[N];
int nxt[N];
bool shit[N];
vector < int > v[N];
bool good[N];
int papa[N];

int tim;
int tin[N];
int tout[N];
bool fucked[N];

int get_p(int x) { return p[x] == x ? x : p[x] = get_p(p[x]); }

void dfs(int x)
{
        tin[x] = ++tim;
        for(int y: v[x]){
                dfs(y);
        }
        tout[x] = tim;
}

int T[N];

void upd(int x, int y)
{
        while(x < N){
                T[x] += y;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += T[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);

                p[i] = i;
                st[i] = true;
                nxt[i] = -1;
        }
        for(int i = 1; i <= k; i++){
                int x, y;
                cin >> x >> y;
                st[y] = false;
                nxt[x] = y;
                x = get_p(x);
                y = get_p(y);
                if(x == y){
                        cout << 0 << "\n";
                        return 0;
                }
                p[x] = y;
        }
        dfs(v[0][0]);
        for(int i = 1; i <= n; i++){
                if(!st[i]){
                        continue;
                }
                int x = i, px = get_p(i);
                while(x != -1){
                        shit[x] = true;
                        if(get(tin[x])){
                                shit[x] = false;
                        }
                        upd(tin[x], 1);
                        upd(tout[x] + 1, -1);
                        c[px] += shit[x];
                        x = nxt[x];
                }
                x = i;
                while(x != -1){
                        upd(tin[x], -1);
                        upd(tout[x] + 1, 1);
                        x = nxt[x];
                }
                papa[px] = i;
        }
        int root = v[0][0];
        assert(shit[root]);
        c[get_p(root)] -= 1;
        good[root] = true;
        queue < int > q;
        vector < int > res;
        q.push(get_p(root));
        while(!q.empty()){
                int x = q.front();
                q.pop();
                x = papa[x];
                while(x != -1){
                        if(!good[x]){
                                cout << 0 << "\n";
                                return 0;
                        }
                        res.push_back(x);
                        for(int y: v[x]){
                                good[y] = true;
                                if(!shit[y]){
                                        continue;
                                }
                                int py = get_p(y);
                                c[py] -= 1;
                                if(!c[py]){
                                        q.push(py);
                                }
                        }
                        x = nxt[x];
                }
        }
        if(res.size() != n){
                cout << 0 << "\n";
                return 0;
        }
        for(int x: res){
                cout << x << " ";
        }
}