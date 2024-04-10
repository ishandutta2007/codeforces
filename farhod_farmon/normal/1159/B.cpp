#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int Q = 7070;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 1e9;
        for(int i = 1; i <= n; i++){
                if(i != 1){
                        res = min(res, min(a[i], a[1]) / (i - 1));
                }
                if(i != n){
                        res = min(res, min(a[i], a[n]) / (n - i));
                }
        }
        cout << res << "\n";
}