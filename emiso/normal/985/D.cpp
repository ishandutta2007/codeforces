#include <bits/stdc++.h>

#define INF (2000000000ULL)
//999999998765257088 1000000000000000000
//999999998765257089 1000000000000000000
using namespace std;
typedef unsigned long long ull;

ull n, H, ans;

ull pa(ull l, ull r) {
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    cin >> n >> H;
    H = min(H, INF);


    if(pa(1, H) + H >= n) {
        ull l = 1, r = H, m;
        while(l <= r) {
            m = (l + r) / 2;

            ull P = pa(1, m);
            if(P > n) r = m - 1;
            else if(P == n) {
                ans = m;
                break;
            }
            else if(P < n && P + m >= n) {
                ans = m + 1;
                break;
            }
            else l = m + 1;
        }
        cout << ans << endl;
    } else {
        ull l = H, r = INF, m;
        while(l <= r) {
            m = (l + r) / 2;
            ull P = pa(1, m) + pa(H, m - 1);

            if(P > n) r = m - 1;
            else if(P == n) {
                ans = m + (m - H);
                break;
            }
            else if(P < n && P + m >= n) {
                ans = m + (m - H) + 1;
                break;
            }
            else if(P < n && P + m + m + 1 >= n) {
                ans = m + (m - H) + 2;
                break;
            }
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}