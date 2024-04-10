#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                long long l, r, m;
                cin >> l >> r >> m;
                long long A, B, C;
                for(long long a = l; a <= r; a++){
                        long long g = m / a;
                        for(int dx = -1; dx <= 1; dx++){
                                long long M = (g + dx) * a;
                                if(M <= 0) continue;
                                long long x = M - m;
                                if(l - r <= x && x <= r - l){
                                        A = a;
                                        B = l;
                                        C = l + abs(x);
                                        if(x < 0){
                                                swap(B, C);
                                        }
                                }
                        }
                }
                cout << A << " " << B << " " << C << "\n";
                assert((m + C - B) % A == 0);
        }
}