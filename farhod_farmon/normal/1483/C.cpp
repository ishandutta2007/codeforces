#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 300300;

long long inf = 1e18;
long long t[4 * N];

void upd(int x, int l, int r, int g, long long y)
{
        t[x] = max(t[x], y);
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        if(g <= m){
                upd(x * 2, l, m, g, y);
        } else{
                upd(x * 2 + 1, m + 1, r, g, y);
        }
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return - inf;
        } else if(l == tl && r == tr){
                return t[x];
        }
        int m = (l + r) / 2;
        return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int n;
int h[N], a[N];
long long d[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> h[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        for(int i = 1; i < 4 * N; i++){
                t[i] = -inf;
        }

        upd(1, 0, n, 0, 0);
        vector < int > v = {0};
        multiset < long long > S;
        for(int i = 1; i <= n; i++){
                while(h[i] < h[v.back()]){
                        S.erase(S.find(a[v.back()] + get(1, 0, n, v[v.size() - 2], v[v.size() - 1] - 1)));
                        v.pop_back();
                }
                d[i] = get(1, 0, n, v.back(), i - 1) + a[i];
                if(!S.empty()){
                        d[i] = max(d[i], *(--S.end()));
                }

                upd(1, 0, n, i, d[i]);
                S.insert(get(1, 0, n, v.back(), i - 1) + a[i]);

                v.push_back(i);
        }

        cout << d[n] << "\n";
}