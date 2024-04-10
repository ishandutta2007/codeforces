#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int get(int k)
{
        int res = 0;
        for(int i = 1; i <= n; i++){
                res += max(0, abs(a[i] - k) - 1);
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 1e9, k;
        for(int i = 1; i <= 100; i++){
                if(get(i) < res){
                        res = get(i);
                        k = i;
                }
        }
        cout << k << " " << res << "\n";
}