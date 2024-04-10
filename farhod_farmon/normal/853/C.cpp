#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;

using namespace std;

struct fenw
{
        int t[N];
        void cler() {for(int i = 0; i < N; i++)t[i] = 0;}
        void upd(int x, int y){
                while(x < N){
                        t[x] += y;
                        x += x & -x;
                }
        }
        int get(int x){
                int res = 0;
                while(x > 0){
                        res += t[x];
                        x -= x & -x;
                }
                return res;
        }
};

int n, q;
int a[N];
long long res[N];
int d1[N], d2[N], d3[N], d4[N];
vector < pair < int, int > > A[N], B[N];

long long f(long long n){ return n * (n - 1) / 2; }

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++){
                d1[i] += 1;
                d3[i] += 1;
                d2[a[i]] += 1;
                d4[a[i]] += 1;
        }
        for(int i = 1; i <= n; i++){
                d1[i] += d1[i - 1];
                d4[i] += d4[i - 1];
        }
        for(int i = n; i >= 1; i--){
                d2[i] += d2[i + 1];
                d3[i] += d3[i + 1];
        }

        for(int i = 1; i <= q; i++){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                res[i] = f(n);
                res[i] -= f(d1[x1 - 1]);
                res[i] -= f(d3[x2 + 1]);
                res[i] -= f(d4[y1 - 1]);
                res[i] -= f(d2[y2 + 1]);

                A[x1 - 1].push_back({y1 - 1, i});
                A[x1 - 1].push_back({y2 + 1, -i});
                B[x2 + 1].push_back({y1 - 1, i});
                B[x2 + 1].push_back({y2 + 1, -i});
        }
        fenw t;
        t.cler();
        for(int i = 1; i <= n; i++){
                t.upd(a[i], 1);
                for(auto p: A[i]){
                        if(p.se > 0) res[p.se] += f(t.get(p.fi));
                        else res[-p.se] += f(t.get(n) - t.get(p.fi - 1));
                }
        }
        t.cler();
        for(int i = n; i >= 1; i--){
                t.upd(a[i], 1);
                for(auto p: B[i]){
                        if(p.se > 0) res[p.se] += f(t.get(p.fi));
                        else res[-p.se] += f(t.get(n) - t.get(p.fi - 1));
                }
        }
        for(int i = 1; i <= q; i++) cout << res[i] << "\n";
}