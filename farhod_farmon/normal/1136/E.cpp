#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

struct node
{
        long long a;
        long long k;
        long long mx;
        long long lz;
        bool ps;
        node()
        {
                k = mx = lz = ps = a = 0;
        }
};

int n;
long long a[N];
long long k[N];
long long sk[N];
node t[4 * N];

void pull(int x)
{
        t[x].mx = max(t[x * 2].mx, t[x * 2 + 1].mx);
        t[x].a = t[x * 2].a + t[x * 2 + 1].a;
        t[x].k = max(t[x * 2].k, t[x * 2 + 1].k);
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x].k = k[l];
                t[x].a = a[l];
                t[x].mx = a[l] - k[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        pull(x);
}

void ch(int x, long long f, int l, int r)
{
        t[x].ps = 1;
        t[x].lz = f;
        t[x].mx = f;
        t[x].a = f * (r - l + 1) + sk[r] - sk[l - 1];
}

void push(int x, int l, int r)
{
        if(!t[x].ps){
                return;
        }
        int m = (l + r) / 2;
        t[x].ps = 0;
        ch(x * 2, t[x].lz, l, m);
        ch(x * 2 + 1, t[x].lz, m + 1, r);
}

void upd(int x, int l, int r, int tl, int tr, long long f)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                ch(x, f, l, r);
                return;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), f);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, f);
        pull(x);
}

long long get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return -1e18;
        }
        if(l == tl && r == tr){
                return t[x].mx;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        long long res = -1e18;
        res = max(res, get(x * 2, l, m, tl, min(m, tr)));
        res = max(res, get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
        pull(x);
        return res;
}

long long sum(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x].a;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        long long res = sum(x * 2, l, m, tl, min(m, tr)) + sum(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        pull(x);
        return res;
}


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 2; i <= n; i++){
                cin >> k[i];
                k[i] += k[i - 1];
                sk[i] = sk[i - 1] + k[i];
        }
        build(1, 1, n);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                char c;
                int x, y;
                cin >> c >> x >> y;
                if(c == 's'){
                        cout << sum(1, 1, n, x, y) << "\n";
                }
                else{
                        long long f = get(1, 1, n, x, x) + y;
                        int l = x, r = n;
                        while(l < r){
                                int m = (l + r) / 2 + 1;
                                if(f > get(1, 1, n, x + 1, m)){
                                        l = m;
                                }
                                else{
                                        r = m - 1;
                                }
                        }
                        upd(1, 1, n, x, l, f);
                }
        }
}