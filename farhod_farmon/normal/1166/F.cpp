#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int q;
int c;
int p[N];
set < int > s[N];
map < int, int > any[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void add(int x, int y, int c)
{
        int &z = any[x][c];
        s[get(x)].insert(y);
        if(z == 0){
                z = y;
                return;
        }

        int px = get(y), py = get(z);
        z = y;

        if(py == px){
                return;
        }
        if(s[py].size() > s[px].size()){
                swap(px, py);
        }
        p[py] = px;
        for(int y: s[py]){
                s[px].insert(y);
        }
        s[py].clear();
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> c >> q;
        for(int i = 1; i <= n; i++){
                p[i] = i;
                s[i].insert(i);
        }
        for(int i = 1; i <= m; i++){
                int x, y, c;
                cin >> x >> y >> c;
                add(x, y, c);
                add(y, x, c);
        }
        for(int i = 1; i <= q; i++){
                char t;
                int x, y, c;
                cin >> t >> x >> y;
                if(t == '?'){
                        x = get(x);
                        if(s[x].find(y) != s[x].end()){
                                cout << "Yes" << "\n";
                        } else{
                                cout << "No" << "\n";
                        }
                } else{
                        cin >> c;
                        add(x, y, c);
                        add(y, x, c);
                }
        }
}