#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303000;

using namespace std;

int n, q;
int a[N], s;
long long t[N];

void upd(int x, int y)
{
        x += 1;
        while(x < N){
                t[x] += y;
                x += x & -x;
        }
}

long long get(int x)
{
        x += 1;
        long long res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

long long solve(int l, int r)
{
        if(l == r){
                return a[l ^ s];
        }
        int h = -1;
        for(int i = 30; i >= 0; i--){
                int x = (l >> i) & 1;
                int y = (r >> i) & 1;
                if(x != y){
                        h = i;
                        break;
                }
        }
        int m = 0;
        for(int i = 30; i > h; i--){
                int x = (l >> i) & 1;
                m += (x << i);
        }
        if(r - l + 1 == (1 << h + 1)){
                m ^= ((s >> h + 1) << h + 1);
                return get(m + (1 << h + 1) - 1) - get(m - 1);
        }
        m += (1 << h) - 1;
        return solve(l, m) + solve(m + 1, r);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> q;
        for(int i = 0; i < (1 << n); i++){
                cin >> a[i];
                upd(i, a[i]);
        }
        for(int i = 1; i <= q; i++){
                int t, x, y;
                cin >> t;
                if(t == 1){
                        cin >> x >> y;
                        x -= 1;
                        x ^= s;
                        upd(x, y - a[x]);
                        a[x] = y;
                } else if(t == 2){
                        cin >> y;
                        s ^= (1 << y) - 1;
                } else if(t == 3){
                        cin >> y;
                        s ^= (1 << y);
                } else{
                        cin >> x >> y;
                        x -= 1;
                        y -= 1;
                        cout << solve(x, y) << "\n";
                }
        }
}