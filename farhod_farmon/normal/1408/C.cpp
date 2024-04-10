#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                long double l;
                cin >> n >> l;
                long double res = 0;
                vector < long double > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                int X = 0, Y = n - 1;
                long double A = 0, B = l;
                while(true){
                        while(X <= Y && A + 1e-10 >= a[X]) X += 1;
                        while(X <= Y && B - 1e-10 <= a[Y]) Y -= 1;
                        if(X > Y) break;
                        long double t = min((a[X] - A) / (X + 1), (B - a[Y]) / (n - Y));
                        res += t;
                        A += t * (X + 1);
                        B -= t * (n - Y);
                }
                if(A + 1e-10 < B){
                        res += (B - A) / (n + 2);
                }
                cout << fixed << setprecision(9) << res << "\n";
        }
}