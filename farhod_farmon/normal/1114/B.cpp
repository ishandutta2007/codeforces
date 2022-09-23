#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
bool used[N];
pair < int, int > a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        long long res = 0;
        sort(a + 1, a + n + 1);
        for(int i = 0; i < m * k; i++){
                used[a[n - i].se] = 1;
                res += a[n - i].fi;
        }
        int cnt = 0;
        cout << res << "\n";
        for(int i = 1; i <= n; i++){
                cnt += used[i];
                if(cnt == m + 1){
                        cout << i - 1 << " ";
                        cnt = 1;
                }
        }
}