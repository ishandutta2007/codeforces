#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        a[n + 1] = 1001;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        if(a[j + 1] - a[i - 1] == j - i + 2){
                                ans = max(ans, j - i + 1);
                        }
                }
        }
        cout << ans << "\n";
}