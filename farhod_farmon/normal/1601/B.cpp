#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int a[N];

int t[4 * N];

int comb(int x, int y)
{
        return a[x] < a[y] ? x : y;
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = l;
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return n + 1;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void upd(int x, int l, int r, int g)
{
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g);
        } else{
                upd(x * 2 + 1, m + 1, r, g);
        }
        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

queue<int> q;
int d[N];
pair<int, int> p[N];

void add(int x, int f)
{
        int y = get(1, 1, n, max(1, x), n);
        while(a[y] <= x){
                q.push(y);
                d[y] = d[f] + 1;
                p[y] = {x, f};
                a[y] = n + 1;
                upd(1, 1, n, y);
                y = get(1, 1, n, max(1, x), n);
        }
}

vector<int> v[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] = i - a[i];
                d[i] = -1;
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[x + i].push_back(i);
        }
        a[n + 1] = n + 1;
        build(1, 1, n);
        add(0, 0);
        while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int y : v[x]){
                        add(y, x);
                }
        }
        if(d[n] == -1){
                cout << -1 << "\n";
                return 0;
        }
        cout << d[n] << "\n";
        while(n){
                cout << p[n].fi << " ";
                n = p[n].se;
        }
}