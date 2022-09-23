#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
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
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                int l = a[i];
                while(i <= l){
                        l = max(l, a[i]);
                        i++;
                }
                i--;
                res++;
        }
        cout << res << "\n";
}