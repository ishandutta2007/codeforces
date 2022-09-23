#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int Q = 7070;

using namespace std;

int n;
int d;
int a[N];
bitset < Q > L, R, cur;

double getF(double a)
{
        return asin(1.0 / sqrt(1.0 + a * a));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> d;
        n *= 2;
        for(int i = 1; i <= n; i += 2){
                cin >> a[i];
                a[i + 1] = a[i] + 1;
        }
        set < int > bad;
        for(int i = 2; i + 1 <= n; i += 2){
                if(a[i + 1] == a[i]){
                        bad.insert(a[i]);
                }
        }
        double pi = acos(-1);
        int q;
        cin >> q;
        int tl = 1, tr = 1;
        while(tr <= n && a[tr] < Q){
                R[a[tr]] = 1;
                tr += 1;
        }
        L[0] = 1;
        for(int i = 1, p = 0; i <= q; i++){
                int x;
                cin >> x;
                L <<= x - p;
                R >>= x - p;
                while(tr <= n && a[tr] - x < Q){
                        if(a[tr] - x >= 0){
                                R[a[tr] - x] = 1;
                        }
                        tr += 1;
                }
                while(tl <= n && a[tl] <= x){
                        if(x - a[tl] < Q){
                                L[x - a[tl]] = 1;
                        }
                        tl += 1;
                }
                double ans = 0;
                if(bad.find(x) != bad.end()){
                        ans = pi;
                } else if(L[0] || R[0]){
                        ans = pi / 2;
                } else{
                        int p1 = (int)L._Find_first();
                        int p2 = (int)R._Find_first();
                        ans = max(ans, getF(min(p1, p2)));
                }
                cur = L & R;
                int p1 = (int)cur._Find_first();
                if(p1 < Q && p1 > 0){
                        ans = max(ans, 2.0 * getF(p1));
                }
                cout << fixed << setprecision(9) << ans << "\n";
                p = x;
        }
}