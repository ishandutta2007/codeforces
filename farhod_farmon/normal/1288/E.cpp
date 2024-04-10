#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600600;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int A[N];
int B[N];
int t[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                a[i] = m + i;
                A[i] = B[i] = i;
                upd(a[i], 1);
        }
        for(int i = m; i >= 1; i--){
                int x;
                cin >> x;
                B[x] = max(B[x], get(a[x]));
                upd(a[x], -1);
                a[x] = i;
                upd(a[x], 1);
                A[x] = min(A[x], get(a[x]));
        }
        for(int i = 1; i <= n; i++){
                A[i] = min(A[i], get(a[i]));
                B[i] = max(B[i], get(a[i]));
        }
        for(int i = 1; i <= n; i++){
                cout << A[i] << " " << B[i] << "\n";
        }
}