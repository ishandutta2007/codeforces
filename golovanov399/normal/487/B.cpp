#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 131072;
const int INF = 1e9;
int tree[N + N];

void init(){
    for (int i = 0; i < N + N; i++)
        tree[i] = INF;
}

int get(int v, int l1, int r1, int l, int r){
    if (l == l1 && r == r1)
        return tree[v];
    int m = (l1 + r1) >> 1;
    if (r <= m)
        return get(v * 2, l1, m, l, r);
    else if (l > m)
        return get(v * 2 + 1, m + 1, r1, l, r);
    else
        return min(get(v * 2, l1, m, l, m), get(v * 2 + 1, m + 1, r1, m + 1, r));
}

void setV(int v, int x){
    v += N;
    tree[v] = x;
    v >>= 1;
    while (v){
        tree[v] = min(tree[v + v], tree[v + v + 1]);
        v >>= 1;
    }
}

pair<int, int> Mn[N], Mx[N];
int l1, r1, l2, r2;

int stupid(int n, int s, int l, const vector<int>& a){
    int ans = n + 1;
    for (int mask = 0; mask < (1 << (n - 1)); mask++){
        bool ok = true;
        int cnt = 1;
        int mn = a[0], mx = a[0];
        for (int i = 0; i < n - 1; i++){
            if (mask & (1 << i)){
                if (cnt < l || mx - mn > s){
                    ok = false;
                    break;
                }
                cnt = 1;
                mn = mx = a[i + 1];
            } else {
                cnt++;
                mn = min(mn, a[i + 1]);
                mx = max(mx, a[i + 1]);
            }
        }
        if (cnt < l || mx - mn > s)
            ok = false;
        if (ok)
            ans = min(ans, __builtin_popcount(mask) + 1);
    }
    if (ans > n)
        return -1;
    else
        return ans;
}

int main(){

    while(1){
        int n;
        cin >> n;
        // n = rand() % 5 + 1;
        int s, L;
        cin >> s >> L;
        // s = rand() % 5 + 1;
        // L = rand() % 5 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
            // a[i] = rand() % 5 + 1;

        int cur = 0;
        l1 = r1 = l2 = r2 = 0;
        Mn[0] = mp(0, a[0]);
        Mx[0] = mp(0, a[0]);
        vector<int> mn(n);
        mn[0] = 0;
        for (int i = 1; i < n; i++){
            bool flag = false;
            while (r1 >= l1 && a[i] <= Mn[r1].y){
                r1--;
                flag = true;
            }
            // if (r1 < l1 || a[i] < Mn[r1].y)
            if (flag)
                Mn[++r1].y = a[i];
            else
                Mn[++r1] = mp(i, a[i]);
            flag = false;
            while (r2 >= l2 && a[i] >= Mx[r2].y){
                r2--;
                flag = true;
            }
            // if (r2 < l2 || a[i] > Mx[r2].y)
            if (flag)
                Mx[++r2].y = a[i];
            else
                Mx[++r2] = mp(i, a[i]);
            int dif = Mx[l2].y - Mn[l1].y;
            while (dif > s){
                if (Mn[l1].x == cur){
                    if (l1 < r1 && Mn[l1 + 1].x == cur + 1)
                        l1++;
                    else
                        Mn[l1].x++;
                }
                if (Mx[l2].x == cur){
                    if (l2 < r2 && Mx[l2 + 1].x == cur + 1)
                        l2++;
                    else
                        Mx[l2].x++;
                }
                dif = Mx[l2].y - Mn[l1].y;
                cur++;
            }
            mn[i] = cur;
            // for (int i = l1; i <= r1; i++){
            //  cerr << "Mn: " << Mn[i].x << " " << Mn[i].y << "\n";
            // }
            // for (int i = l2; i <= r2; i++){
            //  cerr << "Mx: " << Mx[i].x << " " << Mx[i].y << "\n";
            // }
            // cerr << "\n";
        }

        // for (int i = 0; i < n; i++)
        //  cerr << mn[i] << " ";
        // cerr << "\n";
        
        init();
        setV(0, 0);
        for (itn i = 0; i < n; i++){
            int l = mn[i];
            int r = i - L + 1;
            // cerr << i << ":\n " << l << " " << r << "\n";
            if (r < l){
                continue;
            } else
                setV(i + 1, get(1, 0, N - 1, l, r) + 1);
        }
        int ans = tree[N + n];
        if (ans > n)
            ans = -1;

        cout << ans << "\n";
        return 0;

        if (ans != stupid(n, s, L, a)){
            cerr << n << " " << s << " " << L << "\n";
            for (int i = 0; i < n; i++) cerr << a[i] << " ";
            cerr << "\n" << ans << " " << stupid(n, s, L, a) << "\n";
            return 0;
        }

    }

    return 0;
}