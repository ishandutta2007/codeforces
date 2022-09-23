#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 400200;

using namespace std;

int n, m, k;
int t[4 * N];
int lz[4 * N];

void build(int x, int l, int r)
{
        t[x] = r;
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] += y;
                lz[x] += y;
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr)) + lz[x];
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k >> m;
        int G = 400000;
        build(1, 0, G);
        set < pair < int, int > > s;
        multiset < int > t;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                if(s.find({x, y}) == s.end()){
                        s.insert({x, y});
                        y += abs(x - k);
                        t.insert(y);
                        upd(1, 0, G, 0, y - 1, 1);
                } else{
                        s.erase({x, y});
                        y += abs(x - k);
                        t.erase(t.find(y));
                        upd(1, 0, G, 0, y - 1, -1);
                }
                if(t.empty()){
                        cout << 0 << "\n";
                } else{
                        cout << max(0, get(1, 0, G, 0, *(--t.end())) - n) << "\n";
                }
        }
}