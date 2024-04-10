#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int n;
int A[N], B[N];

bool good(int m)
{
        int bal = 0;
        int need = (n + m) - (n + m) / 4;

        A[100] += m;
        for(int i = N - 1, j = need, h = need; i >= 0; i--){
                int g = min(j, A[i]);
                bal += i * g;
                j -= g;

                g = min(h, B[i]);
                bal -= i * g;
                h -= g;
        }
        A[100] -= m;

        return bal >= 0;
}

void solve()
{
        cin >> n;
        for(int i = 0; i < N; i++){
                A[i] = B[i] = 0;
        }
        for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                A[x] += 1;
        }
        for(int i = 0; i < n; i++){
                int x;
                cin >> x;
                B[x] += 1;
        }
        int l = 0, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(good(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
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