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

const int N = 200200;
const int mod = 1e9 + 7;

int n;
int a[N];
int l[N], r[N];
int A[N], B[N], la[N], lb[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1, c1 = 0, c2 = 0; i <= n; i++){
                if(i > 1 && a[i] < a[i - 1]){
                        c1 += 1;
                } else{
                        c1 = 0;
                }
                if(i > 1 && a[i] > a[i - 1]){
                        c2 += 1;
                } else{
                        c2 = 0;
                }
                A[i] = max(A[i - 1], max(c1, c2));
                la[i] = c1;

                if(i > 1 && a[i] > a[i - 1]){
                        l[i] = l[i - 1] + 1;
                }
        }
        for(int i = n, c1 = 0, c2 = 0; i >= 1; i--){
                if(i > 1 && a[i] < a[i + 1]){
                        c1 += 1;
                } else{
                        c1 = 0;
                }
                if(i > 1 && a[i] > a[i + 1]){
                        c2 += 1;
                } else{
                        c2 = 0;
                }
                B[i] = max(B[i + 1], max(c1, c2));
                lb[i] = c1;

                if(i < n && a[i] > a[i + 1]){
                        r[i] = r[i + 1] + 1;
                }
        }

        int res = 0;
        for(int i = 2; i < n; i++){
                if(a[i] < a[i - 1] || a[i] < a[i + 1]){
                        continue;
                }

                int x = l[i], y = r[i], good = 1;

                good &= (x - (1 - x % 2) < y);
                good &= (y - (1 - y % 2) < x);
                good &= (max(x, y) > max(A[i - x - 1], B[i + y + 1]));

                if(x % 2 == 0){
                        good &= (y > x || x > la[i - x]);
                }
                if(y % 2 == 0){
                        good &= (x > y || y > lb[i + y]);
                }

                res += good;
        }
        cout << res << "\n";
}