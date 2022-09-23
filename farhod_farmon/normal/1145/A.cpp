#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 30030;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int solve(int l, int r)
{
        if(l == r){
                return 1;
        }
        bool good = true;
        int m = (l + r) / 2;

        for(int i = l + 1; i <= r; i++){
                if(a[i] < a[i - 1]){
                        good = false;
                }
        }
        if(good){
                return r - l + 1;
        } else{
                return max(solve(l, m), solve(m + 1, r));
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        cout << solve(1, n) << "\n";
}