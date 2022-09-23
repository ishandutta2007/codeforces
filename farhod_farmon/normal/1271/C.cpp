#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, X, Y;
        cin >> n >> X >> Y;

        int A = 0, B = 0, C = 0, D = 0;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;

                A += (y > Y);
                B += (y < Y);
                C += (x > X);
                D += (x < X);
        }

        int res = A;
        res = max(res, B);
        res = max(res, C);
        res = max(res, D);

        cout << res << "\n";
        if(res == A){
                cout << X << " " << Y + 1 << "\n";
        } else if(res == B){
                cout << X << " " << Y - 1 << "\n";
        } else if(res == C){
                cout << X + 1 << " " << Y << "\n";
        } else{
                cout << X - 1 << " " << Y << "\n";
        }
}