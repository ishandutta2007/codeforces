#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n = 10;
int I = 1, J = 3, H = 10;
bool off = false;

long long get(int l, int r)
{
        if(off){
                long long X = max(0, min(J - 1, r) - max(I, l) + 1);
                long long Y = max(0, min(H, r) - max(J, l) + 1);
                return X * (X - 1) / 2 + Y * (Y - 1) / 2;
        }

        cout << "? " << l << " " << r << endl;
        long long x;
        cin >> x;
        return x;
}

long long f(long long x)
{
        long long l = 1, r = 1e9;
        while(l < r){
                long long m = (l + r) / 2;
                if(m * (m - 1) / 2 < x){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        if(l * (l - 1) / 2 == x){
                return l;
        }
        return -1;
}

void solve()
{
        if(!off){
                cin >> n;
        }
        int l = 1, r = n;
        long long P;
        long long all = get(1, n);
        while(l < r){
                int m = (l + r) / 2;
                P = get(1, m);
                if(P > 0 && P < all){
                        break;
                } else if(P > 0) {
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        int m = (l + r) / 2;
        if((f(P) != -1 && get(1, m - 1) + f(P) - 1 == P)) {
                int I = m - f(P) + 1;
                l = m;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        if(get(1, m) == 1ll * (m - I) * (m - I + 1) / 2) {
                                l = m;
                        } else{
                                r = m - 1;
                        }
                }
                int J = l + 1;
                int H = J + f(all - get(1, l)) - 1;
                cout << "! " << I << " " << J << " " << H << endl;
        } else {
                int H = m + f(get(m, n)) - 1;
                r = m;
                while(l < r){
                        int m = (l + r) / 2;
                        if(get(m, n) == 1ll * (H - m) * (H - m + 1) / 2) {
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                int J = l;
                int I = J - f(all - get(l, n));
                cout << "! " << I << " " << J << " " << H << endl;
        }
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}