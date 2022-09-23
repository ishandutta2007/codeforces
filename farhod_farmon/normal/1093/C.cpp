#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const int block = 444;

using namespace std;

int n;
ll a[N];
ll b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n / 2; i++){
                ll s;
                cin >> s;
                int j = n - i + 1;
                if(i == 1){
                        a[i] = 0;
                        a[j] = s;
                        continue;
                }
                ll x = a[i - 1], y = a[j + 1];
                x = max(x, s - y);
                a[i] = x;
                a[n - i + 1] = s - x;
        }
        for(int i = 1; i <= n; i++){
                cout << a[i] << " \n"[i == n];
        }
}