#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n + n; i++){
                if(i <= n){
                        cin >> a[i];
                } else{
                        a[i] = a[i - n];
                }
        }
        int res = 0, cnt = 0;
        for(int i = 1; i <= n + n; i++){
                if(a[i]){
                        cnt++;
                } else{
                        res = max(res, cnt);
                        cnt = 0;
                }
        }
        cout << res << "\n";
}