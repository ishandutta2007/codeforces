#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const long long mod = 1000000007;

using namespace std;

int n;
int q;
int a[N];
int s[N];
int l[N];
int r[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= q; i++){
                cin >> l[i] >> r[i];
        }
        int res = 0;
        for(int i = 1; i <= q; i++){
                for(int j = 1; j <= n; j++){
                        a[j] = s[j] = 0;
                }
                for(int j = 1; j <= q; j++){
                        if(i == j){
                                continue;
                        }
                        a[l[j]]++;
                        a[r[j] + 1]--;
                }
                int all = 0;
                for(int j = 1; j <= n; j++){
                        a[j] += a[j - 1];
                        s[j] = s[j - 1] + (a[j] == 1);
                        all += a[j] > 0;
                }
                for(int j = 1; j <= q; j++){
                        if(i == j){
                                continue;
                        }
                        res = max(res, all - (s[r[j]] - s[l[j] - 1]));
                }
        }
        cout << res << "\n";
}