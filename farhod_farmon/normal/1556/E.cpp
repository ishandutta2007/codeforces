#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N], b[N];
long long s[N];
long long A[N][20];
long long B[N][20];
int L[N];

long long get_min(int l, int r)
{
        int g = L[r - l + 1];
        return min(A[l][g], A[r - (1 << g) + 1][g]);
}

long long get_max(int l, int r)
{
        int g = L[r - l + 1];
        return max(B[l][g], B[r - (1 << g) + 1][g]);
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int  q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                s[i] = a[i] - b[i];

                s[i] += s[i - 1];
                A[i][0] = B[i][0] = s[i];
        }
        for(int i = 2; i < N; i++){
                L[i] = L[i / 2] + 1;
        }
        for(int i = 1; i < 20; i++){
                for(int j = 1; j <= n; j++){
                        if(j + (1 << i) - 1 > n){
                                break;
                        }
                        A[j][i] = min(A[j][i - 1], A[j + (1 << i - 1)][i - 1]);
                        B[j][i] = max(B[j][i - 1], B[j + (1 << i - 1)][i - 1]);
                }
        }
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                if(s[r] - s[l - 1] != 0){
                        cout << -1 << "\n";
                        continue;
                }

                long long mx = get_max(l, r);
                long long mn = get_min(l, r);
                mx -= s[l - 1];
                mn -= s[l - 1];

                cout << max(abs(mx), abs(mn)) << "\n";
        }
}