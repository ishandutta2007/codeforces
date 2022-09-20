#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> A, B;
        pair<int, int> best = {0, 0};
        int X = 1e9, Y = 0;
        for(int i = 0; i < n; i++){
            int l, r, c;
            cin >> l >> r >> c;
            if(A.find(l) == A.end()) A[l] = c;
            else A[l] = min(A[l], c);

            if(B.find(r) == B.end()) B[r] = c;
            else B[r] = min(B[r], c);

            X = min(X, l);
            Y = max(Y, r);
            if(r - l + 1 > best.fi){
                best = {r - l + 1, c};
            } else if(r - l + 1 == best.fi){
                best.se = min(best.se, c);
            }
            int res = A[X] + B[Y];
            if(best.fi == Y - X + 1){
                res = min(res, best.se);
            }
            cout << res << "\n";
        }
    }
}