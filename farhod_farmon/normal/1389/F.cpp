#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400200;

using namespace std;

struct seg
{
        int t[4 * N], lz[4 * N];
        seg(){
                for(int i = 0; i < 4 * N; i++){
                        t[i] = lz[i] = 0;
                }
        }
        void upd(int x, int l, int r, int g, int y)
        {
                if(l == r){
                        t[x] = y;
                        return;
                }
                int m = (l + r) / 2;
                if(g <= m){
                        upd(x * 2, l, m, g, y);
                } else{
                        upd(x * 2 + 1, m + 1, r, g, y);
                }
                t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
        }
        void upd2(int x, int l, int r, int tl, int tr)
        {
                if(tl > tr){
                        return;
                } else if(l == tl && r == tr){
                        t[x] += 1;
                        lz[x] += 1;
                        return;
                }
                int m = (l + r) / 2;
                upd2(x * 2, l, m, tl, min(m, tr));
                upd2(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
                t[x] = max(t[x * 2], t[x * 2 + 1]) + lz[x];
        }
};

int n;
int t[N], l[N], r[N];
seg A, B;
vector < int > fa[N], fb[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                cin >> l[i] >> r[i] >> t[i];
                v.push_back(l[i]);
                v.push_back(r[i]);
        }
        sort(v.begin(), v.end());
        vector < int > nv;
        for(int x: v){
                if(nv.empty() || x > nv.back()){
                        nv.push_back(x);
                }
        }
        v = nv;
        for(int i = 1; i <= n; i++){
                l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
                r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
                if(t[i] == 1){
                        fa[r[i]].push_back(l[i]);
                } else{
                        fb[r[i]].push_back(l[i]);
                }
        }
        int res = 0;
        for(int i = 1; i <= 2 * n; i++){
                for(int j: fa[i]){
                        B.upd2(1, 0, 2 * n, 0, j - 1);
                }
                for(int j: fb[i]){
                        A.upd2(1, 0, 2 * n, 0, j - 1);
                }
                int X = B.t[1], Y = A.t[1];
                A.upd(1, 0, 2 * n, i, X);
                B.upd(1, 0, 2 * n, i, Y);
                res = max(res, max(X, Y));
        }
        cout << res << "\n";
}