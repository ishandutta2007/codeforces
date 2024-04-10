#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n, M, q;
int A[N], B[N], res[N];
int s[N], p[N], f[N];
vector < pair < int*, int > > backup;

int get(int x) { return p[x] == x ? x : get(p[x]); }
int get_f(int x) { return p[x] == x ? 0 : f[x] ^ get_f(p[x]); }

bool make(int i)
{
        if(i < 1 || i > M) return true;
        int x = A[i], y = B[i];
        int px = get(x), py = get(y), cx = get_f(x), cy = get_f(y);

        if(px == py) return (cx != cy);
        if(s[px] < s[py]){
                swap(x, y);
                swap(px, py);
                swap(cx, cy);
        }
        backup.push_back({&p[py], p[py]});
        backup.push_back({&s[px], s[px]});
        backup.push_back({&f[py], f[py]});
        p[py] = px;
        s[px] += s[py];
        f[py] = cx ^ cy ^ 1;
        return true;
}

void roll(int i)
{
        while(backup.size() > i){
                (*backup.back().fi) = backup.back().se;
                backup.pop_back();
        }
}

void solve(int l, int r, int tl, int tr)
{
        if(l > r) return;

        int m = (l + r) / 2;
        int p1 = backup.size();
        bool bad = false;
        for(int i = l; i <= m; i++){
                if(make(i) == false){
                        bad = true;
                        break;
                }
        }
        if(bad){
                for(int i = m; i <= r; i++){
                        res[i] = M + 2;
                }
                roll(p1);
                solve(l, m - 1, tl, tr);
                return;
        }

        int p2 = backup.size();
        res[m] = tr + 1;
        for(int i = tr; i >= tl; i--){
                if(make(i) == false){
                        break;
                }
                res[m] = i;
        }

        roll(p2);
        solve(m + 1, r, res[m], tr);
        roll(p1);
        p2 = backup.size();
        for(int i = tr; i >= res[m]; i--){
                make(i);
        }
        solve(l, m - 1, tl, res[m] - 1);
        roll(p2);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> M >> q;
        for(int i = 1; i <= M; i++){
                cin >> A[i] >> B[i];
        }

        for(int i = 1; i <= n; i++){
                p[i] = i;
                s[i] = 1;
        }

        solve(0, M - 1, 1, M);

        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                if(res[l - 1] > r + 1){
                        cout << "YES\n";
                } else{
                        cout << "NO\n";
                }
        }
}