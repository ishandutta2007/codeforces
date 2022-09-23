#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 100100;

int n;
int m;
int a[N];
int b[N];
bool used[N];

void solve()
{
        long long res = 0;

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                used[i] = 0;
        }
        int h = 0;
        for(int i = 1; i <= m; i++){
                cin >> b[i];

                if(used[b[i]]){
                        res += 1;
                        continue;
                }

                while(!used[b[i]]){
                        h += 1;
                        used[a[h]] = true;
                }

                res += 2 * (h - i) + 1;
        }

        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}