#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int k;
int a[N];
long long s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        //k += 1;
        sort(a + 1, a + n + 1);
        long long res = 0;
        for(int i = n; i >= 1; i--){
                s[i] = s[i + 1] + a[i];
                res += 1ll * (i - 1) * a[i];
        }
        int shit = k;
        for(int i = 1; i <= n; i++){
                if(s[i] > 0){
                        break;
                }
                if(shit == k){
                        shit = 0;
                        continue;
                }
                res -= s[i];
                shit += 1;
        }
        cout << res << "\n";
}